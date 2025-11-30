#ifndef OBSERVABLE_H
#define OBSERVABLE_H

#include <vector>
#include "observer.h"

class Observable {
public:
    void addObserver(Observer* obs) {
        observers.push_back(obs);
    }

protected:
    void notifyObservers() {
        for (Observer* obs : observers) {
            obs->update();
        }
    }

private:
    std::vector<Observer*> observers;
};

#endif
