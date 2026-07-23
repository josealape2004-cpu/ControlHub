#include "wifi.h"

#include <ESP8266WiFi.h>

#include "config.h"

namespace WifiService {

void begin() {

    WiFi.mode(WIFI_AP);

    WiFi.softAPConfig(
        Config::AP_IP,
        Config::GATEWAY,
        Config::SUBNET
    );

    WiFi.softAP(
        Config::WIFI_SSID,
        Config::WIFI_PASSWORD
    );
}

}
