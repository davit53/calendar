#include "taskview.h"

#include <QLabel>
#include <QVBoxLayout>

TaskView::TaskView(const QString titleOfTask, const QString description, QWidget *parent) : QWidget(parent),
    //make the box for the task and the text variables
    mTitleLabel(new QLabel(titleOfTask, this)),
    mTaskDescriptionLabel(new QLabel(description, this)),
    mLayout(new QVBoxLayout(this))
{
    //make the title the name of the window
    setWindowTitle(titleOfTask);
    //set to decent size
    resize(270, 150);

    //make sure description wraps if it is longer than page width
    mTaskDescriptionLabel->setWordWrap(true);

    //create title and desc label to show which is which in task view
    QLabel* titleHeader = new QLabel("Task:", this);
    QLabel* descHeader = new QLabel("Description:", this);

    //make labels bold
    QFont boldFont;
    boldFont.setBold(true);
    titleHeader->setFont(boldFont);
    descHeader->setFont(boldFont);

    //adding all widgets
    mLayout->addWidget(titleHeader);
    mLayout->addWidget(mTitleLabel);
    mLayout->addWidget(descHeader);
    mLayout->addWidget(mTaskDescriptionLabel);
    setLayout(mLayout);

}

//methods for setting task and desc
void TaskView::setTaskTitle(const QString titleOfTask)
{
    mTitleLabel->setText(titleOfTask);
    setWindowTitle(titleOfTask);
}
void TaskView::setTaskDescription(const QString description)
{
    mTaskDescriptionLabel->setText(description);
}
