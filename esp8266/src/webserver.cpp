#include "webserver.h"

#include <ESP8266WebServer.h>

#include "config.h"

#include "../generated/index_html.h"
#include "../generated/style_css.h"
#include "../generated/app_js.h"
#include "../generated/controller_js.h"
#include "../generated/websocket_js.h"

namespace {

ESP8266WebServer server(Config::HTTP_PORT);

}

namespace WebServerService {

void begin() {

    server.on(
        "/",
        HTTP_GET,
        []() {

            server.send_P(
                200,
                "text/html",
                INDEX_HTML
            );

        }
    );

    server.on(
        "/css/styles.css",
        HTTP_GET,
        []() {

            server.send_P(
                200,
                "text/css",
                STYLE_CSS
            );

        }
    );

    server.on(
        "/js/app.js",
        HTTP_GET,
        []() {

            server.send_P(
                200,
                "application/javascript",
                APP_JS
            );

        }
    );

    server.on(
        "/js/controller.js",
        HTTP_GET,
        []() {

            server.send_P(
                200,
                "application/javascript",
                CONTROLLER_JS
            );

        }
    );

    server.on(
        "/js/websocket.js",
        HTTP_GET,
        []() {

            server.send_P(
                200,
                "application/javascript",
                WEBSOCKET_JS
            );

        }
    );

    server.begin();

}

void loop() {

    server.handleClient();

}

}
