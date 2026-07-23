robotSocket.connect();

/* ==========================================
   UI -> Controller
========================================== */

const actions = {

    F: () => robotController.forward(),

    B: () => robotController.backward(),

    L: () => robotController.left(),

    R: () => robotController.right(),

    S: () => robotController.stop()

};

document
    .querySelectorAll("[data-command]")
    .forEach((button) => {

        const command = button.dataset.command;

        const stop = (event) => {

            event.preventDefault();

            actions.S();

        };

        button.addEventListener(

            "pointerdown",

            (event) => {

                event.preventDefault();

                button.setPointerCapture(
                    event.pointerId
                );

                actions[command]?.();

            }

        );

        button.addEventListener(
            "pointerup",
            stop
        );

        button.addEventListener(
            "pointercancel",
            stop
        );

        button.addEventListener(
            "pointerleave",
            stop
        );

    });

window.addEventListener(

    "blur",

    () => {

        robotController.stop();

    }

);

document.addEventListener(

    "visibilitychange",

    () => {

        if (document.hidden) {

            robotController.stop();

        }

    }

);

/* ==========================================
   Connection Status
========================================== */

const connection =
    document.getElementById(
        "connection-status"
    );

document.addEventListener(

    "robot:connected",

    () => {

        connection.textContent =
            "Conectado";

        connection.className =
            "status-box connected";

    }

);

document.addEventListener(

    "robot:disconnected",

    () => {

        connection.textContent =
            "Desconectado";

        connection.className =
            "status-box disconnected";

        robotController.stop();

    }

);

/* ==========================================
   Sensor Status
========================================== */

const sensor =
    document.getElementById(
        "status"
    );

document.addEventListener(

    "robot:message",

    (event) => {

        const msg = event.detail;

        if (msg === "CONTROL_GRANTED") {

            connection.textContent =
                "Control asignado";

            connection.className =
                "status-box connected";

            return;

        }

        if (msg === "CONTROL_DENIED") {

            connection.textContent =
                "Control ocupado";

            connection.className =
                "status-box disconnected";

            robotController.stop();

            return;

        }

        if (msg === "PRESENCIA:SI") {

            sensor.textContent =
                "Obstáculo detectado";

            sensor.className =
                "status-box danger";

        }

        else if (msg === "PRESENCIA:NO") {

            sensor.textContent =
                "Sin obstáculos";

            sensor.className =
                "status-box safe";

        }

    }

);
