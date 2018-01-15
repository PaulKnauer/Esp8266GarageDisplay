#ifndef MqttClient_h
#define MqttClient_h

#include <ESP8266WiFi.h>
#include <PubSubClient.h>

#include "UserConfig.h"
#include "EventCallback.h"

class MqttClient {
  public:
    MqttClient();
    void connect();
    void loop();
    void setCallback(EventCallback *eventCallback);
  private:
    WiFiClient espClient;
    PubSubClient client;
    EventCallback *eventCallback;
    void callback(char* topic, byte* payload, unsigned int length);
};

#endif
