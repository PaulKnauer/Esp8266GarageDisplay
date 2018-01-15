#include "DistanceState.h"

void DistanceState::callback(byte *payload, unsigned int length) {
  char payloadChr[length];
  for (int i = 0 ; i < length ; i++) {
    payloadChr[i] = (char) payload[i];
  }
  distance = atoi(payloadChr);
}

int DistanceState::getDistance() {
  return distance;
}

int DistanceState::getState() {
  if (distance >= DOOR_CLOSED_DISTANCE) {
    lastState = DOOR_CLOSED;
    return DOOR_CLOSED;
  } else if (distance < DOOR_CLOSED_DISTANCE && distance > DOOR_OPEN_DISTANCE && lastState == DOOR_CLOSED) {
    return DOOR_OPENING;
  } else if (distance <= DOOR_OPEN_DISTANCE) {
    lastState = DOOR_OPEN;
    return DOOR_OPEN;
  } else if (distance < DOOR_CLOSED_DISTANCE && distance > DOOR_OPEN_DISTANCE && lastState == DOOR_OPEN) {
    return DOOR_CLOSING;
  }
}

