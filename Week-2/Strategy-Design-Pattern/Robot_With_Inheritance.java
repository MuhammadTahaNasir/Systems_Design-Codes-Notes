abstract class Robot {
    public void walk() {
        System.out.println("Robot is walking normally");
    }

    public void talk() {
        System.out.println("Robot is talking normally");
    }

    public void fly() {
        System.out.println("Robot cannot fly");
    }

    public abstract void projection();
}

abstract class FlyableRobot extends Robot {
    @Override
    public void fly() {
        System.out.println("Flying with wings");
    }
}

class SparrowRobot extends FlyableRobot {
    @Override
    public void projection() {
        System.out.println("Sparrow Robot projection: Bird-like and agile");
    }
}

class CrowRobot extends FlyableRobot {
    @Override
    public void projection() {
        System.out.println("Crow Robot projection: Dark and swift");
    }
}

public class Main {
    public static void main(String[] args) {
        Robot sparrow = new SparrowRobot();
        Robot crow = new CrowRobot();

        System.out.println("Sparrow Robot:");
        sparrow.walk();
        sparrow.talk();
        sparrow.fly();
        sparrow.projection();

        System.out.println("\nCrow Robot:");
        crow.walk();
        crow.talk();
        crow.fly();
        crow.projection();
    }
}