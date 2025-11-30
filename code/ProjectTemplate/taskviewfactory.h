/*
*
* Author: Davit Najaryan
* Desccription: This class is a creational pattern called factory to handle TaskView object creation
*
*/


#ifndef TASKVIEWFACTORY_H
#define TASKVIEWFACTORY_H
#include <QString>

class TaskView;

class taskViewFactory
{

public:

    //static method so we dont have to make a TaskViewFacotry object itself
    //return new TaskView object
    static TaskView* create(const QString title, const QString description);

};

#endif // TASKVIEWFACTORY_H
