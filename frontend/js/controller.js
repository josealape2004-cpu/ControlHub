class RobotController {

    send(command) {

        robotSocket.send(command);

    }

    forward() {

        this.send("F");

    }

    backward() {

        this.send("B");

    }

    left() {

        this.send("L");

    }

    right() {

        this.send("R");

    }

    stop() {

        this.send("S");

    }

}

window.robotController = new RobotController();
