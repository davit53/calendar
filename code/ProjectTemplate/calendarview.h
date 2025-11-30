#ifndef CALENDARVIEW_H
#define CALENDARVIEW_H

#include <QWidget>
#include <QCalendarWidget>
#include <QListWidget>
#include <QPushButton>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLabel>
#include <QDate>

#include "taskmanager.h"

class QListWidgetItem;

//displays calendar UI and updates automatically through Observer pattern.
class CalendarView : public QWidget, public Observer
{
    Q_OBJECT

public:
    explicit CalendarView(TaskManager *manager, QWidget *parent = nullptr);

    //observer update(), called when TaskManager changes aka when a task is added
    void update() override;

//slots to handle user interactions
private slots:
    void handleAddTask();
    void handleDateChanged();
    void taskClicked(QListWidgetItem* item);

//widgets and buttons for calendar view and task data manager
private:
    TaskManager *manager;
    QCalendarWidget *calendar;
    QListWidget *taskList;
    QPushButton *addTaskButton;
    QLabel *dateLabel;

    void loadTasksForDate(const QDate &date);
};

#endif // CALENDARVIEW_H