#include "MqttClient.h"

MqttClient::MqttClient() {
  espClient = WiFiClient();
  client = PubSubClient(espClient);
  pinMode(BUILTIN_LED, OUTPUT);
  client.setServer(MQTT_SERVER, MQTT_SERVERPORT);
  client.setCallback([this] (char* topic, byte * payload, unsigned int length) {
    this->callback(topic, payload, length);
  });
}

void MqttClient::connect() {
  while (!client.connected()) {
    if (client.connect(MQTT_CLIENT_NAME, MQTT_USERNAME, MQTT_PASSWORD)) {
      client.subscribe(MQTT_DISTANCE_SUBSCRIBE_TOPIC);
    } else {
      delay(5000);
    }
  }
}

void MqttClient::loop() {
  if (!client.connected()) {
    this->connect();
  }
  client.loop();
}

void MqttClient::setCallback(EventCallback *eventCallback) {
  this->eventCallback = eventCallback;
}

void MqttClient::callback(char* topic, byte* payload, unsigned int length) {
  if (eventCallback != NULL ) {
    eventCallback->callback(payload, length);
  }
}

