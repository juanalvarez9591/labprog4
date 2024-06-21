#ifndef IOBSERVER_H
#define IOBSERVER_H

#include <string>
#include "DTNotificacion.h"

class IObserver {
public:
    virtual void update(DTNotificacion notificacion) = 0;
    virtual ~IObserver() {}
};

#endif