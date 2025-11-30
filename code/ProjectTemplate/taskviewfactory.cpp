#include "taskviewfactory.h"
#include "taskview.h"

TaskView* taskViewFactory::create(const QString title, const QString description)
{

    //can use this class to create diff types of tasks

    return new TaskView(title, description, nullptr);

}
