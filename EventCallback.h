#ifndef EventCallback_h
#define EventCallback_h

#include "Arduino.h"

class EventCallback {
  public:
    virtual void callback(byte* payload, unsigned int length) = 0;
};

#endif
