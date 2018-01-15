#include <ESP8266WiFi.h>

#include "UserConfig.h"
#include "BiColorMatrix.h"
#include "MqttClient.h"
#include "DistanceState.h"

MqttClient *client;
BiColorMatrix *matrix = new BiColorMatrix();
DistanceState *state = new DistanceState();

void setup() {
  setUpWiFi();
  client = new MqttClient();
  client->setCallback(state);
}

void loop() {
  delay(DELAY);
  client->loop();
  if (state->getState() == DOOR_CLOSED) {
    matrix->closedAnimation();
  } else if (state->getState() == DOOR_OPENING) {
    matrix->moving(state->getDistance());
  } else if (state->getState() == DOOR_OPEN) {
    matrix->openAnimation();
  } else if (state->getState() == DOOR_CLOSING) {
    matrix->closingAnimation();
    matrix->moving(state->getDistance());
  }
}

void setUpWiFi() {
  delay(10);
  WiFi.begin(WLAN_SSID, WLAN_PASSWORD);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
  }
}

