class RobotController{

    forward(){

        robotSocket.send("F");

    }

    backward(){

        robotSocket.send("B");

    }

    left(){

        robotSocket.send("L");

    }

    right(){

        robotSocket.send("R");

    }

    stop(){

        robotSocket.send("S");

    }

}

window.robotController=new RobotController();
