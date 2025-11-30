#include "calendarview.h"
#include "taskview.h"
#include "taskviewfactory.h"
#include <QInputDialog>
#include <QListWidgetItem>
#include <QLineEdit>

CalendarView::CalendarView(TaskManager *manager, QWidget *parent)
    : QWidget(parent), manager(manager)
{
    calendar = new QCalendarWidget(this);
    taskList = new QListWidget(this);
    addTaskButton = new QPushButton("Add Task", this);
    dateLabel = new QLabel("Select a date to view tasks", this);

    // layout
    QVBoxLayout *layout = new QVBoxLayout(this);
    layout->addWidget(calendar);
    layout->addWidget(dateLabel);
    layout->addWidget(taskList);
    layout->addWidget(addTaskButton);
    setLayout(layout);

    // Register as Observer
    manager->addObserver(this);

    // signals
    connect(calendar, &QCalendarWidget::selectionChanged,
            this, &CalendarView::handleDateChanged);

    connect(addTaskButton, &QPushButton::clicked,
            this, &CalendarView::handleAddTask);

    connect(taskList, &QListWidget::itemClicked,
            this, &CalendarView::taskClicked);

    loadTasksForDate(calendar->selectedDate());
}

void CalendarView::update()
{
    // Called automatically when TaskManager notifies observers
    loadTasksForDate(calendar->selectedDate());
}

void CalendarView::handleDateChanged()
{
    QDate date = calendar->selectedDate();
    loadTasksForDate(date);
}

void CalendarView::handleAddTask()
{
    bool ok = false;
    QString title = QInputDialog::getText(
        this, "New Task", "Task name:", QLineEdit::Normal, "", &ok);

    QString description = QInputDialog::getText(this, "Task Description", "Description", QLineEdit::Normal, "", &ok);

    if (ok && !title.isEmpty()) {
        manager->addTask(title, description); //notify observers automatically
    }


}

void CalendarView::loadTasksForDate(const QDate &date)
{
    taskList->clear();
    dateLabel->setText("Tasks for " + date.toString("ddd, MMM d yyyy"));

    //store list of tasks from task mamager
    const std::vector<TaskManager::Task> &tasks = manager -> getTasks();

    // show the title in the list
    for (const TaskManager::Task &t : tasks)
    {

        QListWidgetItem *item = new QListWidgetItem(t.title, taskList);

        item -> setData(Qt::UserRole, t.description);

    }
}

void CalendarView::taskClicked(QListWidgetItem* item)
{
    if (!item)
    {
        return;
    }

    //get the title and description of task and store it
    QString titleOfTask = item -> text();
    QString descriptionOfTask = item -> data(Qt::UserRole).toString();

    TaskView* myTask = taskViewFactory::create(titleOfTask, descriptionOfTask);

    //clean up
    myTask->setAttribute(Qt::WA_DeleteOnClose);
    myTask->show();
}