# Robot Controller

Sistema de control remoto para una plataforma diferencial utilizando un **PIC18F45K22** y un **ESP8266 NodeMCU v3**.

El proyecto implementa una interfaz web responsiva que permite controlar el movimiento del robot desde cualquier dispositivo conectado al punto de acceso WiFi generado por el ESP8266.

---

# Arquitectura

```
robot-controller/
│
├── frontend/
│   ├── css/
│   │   └── styles.css
│   │
│   ├── js/
│   │   ├── websocket.js
│   │   ├── controller.js
│   │   └── app.js
│   │
│   ├── assets/
│   ├── index.html
│   └── README.md
│
├── generated/
│   ├── index_html.h
│   ├── style_css.h
│   └── app_js.h
│
├── esp8266/
│   ├── src/
│   ├── include/
│   └── README.md
│
├── pic18f45k22/
│   ├── nbproject/
│   ├── src/
│   └── README.md
│
├── scripts/
│   └── build-web.js
│
└── README.md
```

---

# Flujo del sistema

```
                Navegador

        HTML + CSS + JavaScript
                 │
                 │ WebSocket
                 ▼
        ESP8266 NodeMCU v3
     HTTP Server + WebSocket
                 │
                 │ UART
                 ▼
           PIC18F45K22
      Control de Motores
      Lectura de Sensores
```

---

# Responsabilidades

## Frontend

La interfaz web se ejecuta completamente en el navegador del usuario.

Responsabilidades:

- Mostrar el panel de control.
- Gestionar la interacción del usuario.
- Establecer la conexión WebSocket con el ESP8266.
- Mostrar el estado de conexión.
- Mostrar el estado del sensor infrarrojo.

El frontend desconoce completamente cómo funciona el hardware.

---

## ESP8266

El ESP8266 actúa como servidor del sistema.

Responsabilidades:

- Crear el Access Point WiFi.
- Servir los archivos HTML, CSS y JavaScript.
- Mantener la conexión WebSocket.
- Traducir los mensajes WebSocket hacia UART.
- Enviar al navegador los eventos recibidos desde el PIC.

El ESP8266 no contiene lógica de movimiento del robot.

---

## PIC18F45K22

El PIC es el controlador principal del robot.

Responsabilidades:

- Control de motores.
- Lectura de sensores.
- Comunicación UART con el ESP8266.
- Ejecución de la lógica de control.

El PIC desconoce completamente la existencia de HTML, CSS, JavaScript o WebSockets.

---

# Comunicación

Frontend → ESP8266

```
F
B
L
R
S
```

ESP8266 → Frontend

```
PRESENCIA:SI
PRESENCIA:NO
```

---

# Flujo de desarrollo

Durante el desarrollo, el frontend permanece separado del firmware del ESP8266.

```
frontend/

↓

scripts/build-web.js

↓

generated/

↓

Compilación del ESP8266
```

El script `build-web.js` convierte automáticamente los archivos HTML, CSS y JavaScript en encabezados (`.h`) que posteriormente son incluidos dentro del firmware del ESP8266.

De esta forma, el frontend puede desarrollarse como una aplicación web convencional sin modificar el código del microcontrolador.
