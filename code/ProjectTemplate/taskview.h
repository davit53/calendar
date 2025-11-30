/**
 * Author: Davit Najaryan
 * Description: This class is used to display a single task when clicked on in the main window (CalendarView)
 *
 */

#ifndef TASKVIEW_H
#define TASKVIEW_H

#include <QWidget>


class QLabel;
class QVBoxLayout;

class TaskView : public QWidget
{

    Q_OBJECT

public:

//constructor with display text and
    explicit TaskView(const QString titleOfTask, const QString description, QWidget *parent = nullptr);

    void setTaskTitle(QString titleOfTask);
    void setTaskDescription(const QString description);

//text for the title, task and pointer to vertical layout
private:

//use pointes so we dont have to delete manually after window is closed
    QLabel* mTitleLabel;
    QLabel* mTaskDescriptionLabel;
    QVBoxLayout* mLayout;

};

#endif // TASKVIEW_H
