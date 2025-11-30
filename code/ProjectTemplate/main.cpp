#include <QApplication>
#include "calendarview.h"
#include "taskmanager.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    //create the TaskManager (Observable)
    TaskManager *manager = new TaskManager();

    //pass TaskManager into CalendarView, which is observer so we keep ui updated
    CalendarView window(manager);

    //showing our app window
    window.setWindowTitle("Smart Scheduler");
    window.resize(800, 500);
    window.show();

    return app.exec();
}