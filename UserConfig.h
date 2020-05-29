#ifndef UserConfig_h
#define UserConfig_h

#define WLAN_SSID        "yourssid"
#define WLAN_PASSWORD    "yourwifipassword"
#define DELAY 100

#define MQTT_CLIENT_NAME "GarageDoorDisplay1"
#define MQTT_SERVER      "192.168.2.9"
#define MQTT_SERVERPORT  1883
#define MQTT_USERNAME    "hassio"
#define MQTT_PASSWORD    "hassio"

#define MQTT_DISTANCE_SUBSCRIBE_TOPIC "/Garage/Door1/Distance"

#define DOOR_CLOSED_DISTANCE 200
#define DOOR_OPEN_DISTANCE 10

#endif
