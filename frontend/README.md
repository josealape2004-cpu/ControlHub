## Estructura

frontend/
│
├── index.html
├── css/
│     └── styles.css
│
├── js/
│     ├── websocket.js
│     ├── controller.js
│     └── app.js
│
└── assets/

## Probar en la consola estos comandos, para ver si funciona sin hardware (mockup

1.
-----------------------------------------
document.dispatchEvent(
    new CustomEvent("robot:connected")
);
--------------------------------
2.
----------------------------
document.dispatchEvent(
    new CustomEvent(
        "robot:message",
        {
            detail: "PRESENCIA:SI"
        }
    )
);
-----------------------------

es probable que toque colocar el comando allow pasting
