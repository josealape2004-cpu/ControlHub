#include "wifi.h"
#include "uart.h"
#include "webserver.h"
#include "websocket.h"

void setup() {

    WifiService::begin();

    UartService::begin();

    WebServerService::begin();

    WebSocketService::begin();

}

void loop() {

    WebServerService::loop();

    WebSocketService::loop();

    UartService::loop();

}
