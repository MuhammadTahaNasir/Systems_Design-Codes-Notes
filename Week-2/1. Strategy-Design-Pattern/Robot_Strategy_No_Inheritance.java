interface Walkable {
    void walk();
}

interface Talkable {
    void talk();
}

interface Flyable {
    void fly();
}

interface Projectable {
    void projection();
}

class NormalWalk implements Walkable {
    @Override
    public void walk() {
        System.out.println("Walking normally");
    }
}

class NoWalk implements Walkable {
    @Override
    public void walk() {
        System.out.println("Cannot walk");
    }
}

class NormalTalk implements Talkable {
    @Override
    public void talk() {
        System.out.println("Talking normally");
    }
}

class NoTalk implements Talkable {
    @Override
    public void talk() {
        System.out.println("Cannot talk");
    }
}

class NormalFly implements Flyable {
    @Override
    public void fly() {
        System.out.println("Flying with wings");
    }
}

class NoFly implements Flyable {
    @Override
    public void fly() {
        System.out.println("Cannot fly");
    }
}

class CompanionProjection implements Projectable {
    @Override
    public void projection() {
        System.out.println("Companion Robot projection: Friendly and sleek");
    }
}

class WorkerProjection implements Projectable {
    @Override
    public void projection() {
        System.out.println("Worker Robot projection: Sturdy and functional");
    }
}

class Robot {
    Walkable walkBehavior;
    Talkable talkBehavior;
    Flyable flyBehavior;
    Projectable projectionBehavior;

    public Robot(Walkable walkBehavior, Talkable talkBehavior, Flyable flyBehavior, Projectable projectionBehavior) {
        this.walkBehavior = walkBehavior;
        this.talkBehavior = talkBehavior;
        this.flyBehavior = flyBehavior;
        this.projectionBehavior = projectionBehavior;
    }

    public void walk() {
        walkBehavior.walk();
    }

    public void talk() {
        talkBehavior.talk();
    }

    public void fly() {
        flyBehavior.fly();
    }

    public void projection() {
        projectionBehavior.projection();
    }
}

public class Main {
    public static void main(String[] args) {
        Robot companion = new Robot(new NormalWalk(), new NormalTalk(), new NoFly(), new CompanionProjection());
        Robot worker = new Robot(new NoWalk(), new NoTalk(), new NormalFly(), new WorkerProjection());

        System.out.println("Companion Robot:");
        companion.walk();
        companion.talk();
        companion.fly();
        companion.projection();

        System.out.println("\nWorker Robot:");
        worker.walk();
        worker.talk();
        worker.fly();
        worker.projection();
    }
}
