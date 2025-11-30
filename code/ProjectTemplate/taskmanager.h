#ifndef TASKMANAGER_H
#define TASKMANAGER_H

#include <vector>
#include "taskviewfactory.h"
#include "observable.h"
#include <QString>

class TaskManager : public Observable
{
public:

    struct Task
    {
        QString title;
        QString description;
    };

    TaskManager() = default;

    void addTask(const QString title, const QString description)
    {
        tasks.push_back({title, description});
        notifyObservers();        //notifies CalendarView + TaskView
    }

    const std::vector<Task>& getTasks() const
    {
        return tasks;
    }

private:
    std::vector<Task> tasks;
};

#endif // TASKMANAGER_H
