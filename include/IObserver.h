#ifndef IOBSERVER_H
#define IOBSERVER_H

#include <string>

class IObserver {
public:
    virtual void update(std::string message) = 0;
    virtual std::string getNickname() = 0;
    virtual ~IObserver() {}
};

#endif