TEMPLATE = app
CONFIG += console c++17
CONFIG -= app_bundle

SOURCES += \
        calendarview.cpp \
        main.cpp \
        taskview.cpp \
        taskviewfactory.cpp

HEADERS += \
    build/calendarview.h \
    calendarview.h \
    observable.h \
    observer.h \
    taskmanager.h \
    taskview.h \
    taskviewfactory.h

QT += widgets