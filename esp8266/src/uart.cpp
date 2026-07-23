#include "uart.h"

#include <Arduino.h>

#include "config.h"
#include "websocket.h"

namespace {

String rxBuffer;

String lastPresenceState;

constexpr size_t MAX_BUFFER_SIZE = 32;

}

namespace UartService {

void begin() {

    Serial.begin(Config::UART_BAUDRATE);

    rxBuffer.reserve(MAX_BUFFER_SIZE);

    lastPresenceState.reserve(16);

}

void sendCommand(char command) {

    Serial.write(command);

}

void loop() {

    while (Serial.available()) {

        char c = static_cast<char>(Serial.read());

        if (c == '\r') {

            continue;

        }

        if (c == '\n') {

            rxBuffer.trim();

            String currentState;

            if (

                rxBuffer == "ALERTA:OBSTACULO" ||
                rxBuffer == "PRESENCIA:SI"

            ) {

                currentState = "PRESENCIA:SI";

            }
            else if (rxBuffer == "PRESENCIA:NO") {

                currentState = "PRESENCIA:NO";

            }

            if (

                currentState.length() > 0 &&
                currentState != lastPresenceState

            ) {

                lastPresenceState = currentState;

                WebSocketService::broadcast(currentState);

            }

            rxBuffer.clear();

            continue;

        }

        if (rxBuffer.length() < MAX_BUFFER_SIZE) {

            rxBuffer += c;

        }

    }

}

}
