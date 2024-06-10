#ifndef IOBSERVER_H
#define IOBSERVER_H

#include <string>

class IObserver {
public:
    virtual void notify(std::string message) = 0;
    virtual ~IObserver() {}
};

#endif