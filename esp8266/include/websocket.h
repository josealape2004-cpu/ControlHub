#pragma once

#include <Arduino.h>

namespace WebSocketService {

void begin();

void loop();

void broadcast(String message);

}
