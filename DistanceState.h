#ifndef DistanceState_h
#define DistanceState_h

#define DOOR_CLOSED 0
#define DOOR_OPENING 1
#define DOOR_OPEN 2
#define DOOR_CLOSING 3

#include "UserConfig.h"
#include "EventCallback.h"

class DistanceState : public EventCallback {
  public:
    void callback(byte *payload, unsigned int length);
    int getDistance();
    int getState();
  private:
    int distance = 0;
    int lastState = 0;
};

#endif

