#pragma once

#include <Arduino.h>
#include <ESP8266WiFi.h>

namespace Config {

constexpr char WIFI_SSID[] = "Robot-Control";

constexpr char WIFI_PASSWORD[] = "";

constexpr uint16_t HTTP_PORT = 80;

constexpr uint16_t WS_PORT = 81;

constexpr uint32_t UART_BAUDRATE = 9600;

const IPAddress AP_IP(192,168,4,1);

const IPAddress GATEWAY(192,168,4,1);

const IPAddress SUBNET(255,255,255,0);

}
