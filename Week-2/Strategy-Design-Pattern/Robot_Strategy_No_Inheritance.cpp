#include <iostream>
#include <string>

using namespace std; 

// Behavior interfaces
class Walkable
{
public:
    virtual void walk() = 0;
    virtual ~Walkable() {}
};

class Talkable
{
public:
    virtual void talk() = 0;
    virtual ~Talkable() {}
};

class Flyable
{
public:
    virtual void fly() = 0;
    virtual ~Flyable() {}
};

class Projectable
{
public:
    virtual void projection() = 0;
    virtual ~Projectable() {}
};

// Concrete behavior classes
class NormalWalk : public Walkable
{
public:
    void walk() override
    {
        cout << "Walking normally" << endl;
    }
};

class NoWalk : public Walkable
{
public:
    void walk() override
    {
        cout << "Cannot walk" << endl;
    }
};

class NormalTalk : public Talkable
{
public:
    void talk() override
    {
        cout << "Talking normally" << endl;
    }
};

class NoTalk : public Talkable
{
public:
    void talk() override
    {
        cout << "Cannot talk" << endl;
    }
};

class NormalFly : public Flyable
{
public:
    void fly() override
    {
        cout << "Flying with wings" << endl;
    }
};

class NoFly : public Flyable
{
public:
    void fly() override
    {
        cout << "Cannot fly" << endl;
    }
};

class CompanionProjection : public Projectable
{
public:
    void projection() override
    {
        cout << "Companion Robot projection: Friendly and sleek" << endl;
    }
};

class WorkerProjection : public Projectable
{
public:
    void projection() override
    {
        cout << "Worker Robot projection: Sturdy and functional" << endl;
    }
};

// Robot class using composition
class Robot
{
private:
    Walkable *walkBehavior;
    Talkable *talkBehavior;
    Flyable *flyBehavior;
    Projectable *projectionBehavior;

public:
    Robot(Walkable *walk, Talkable *talk, Flyable *fly, Projectable *project)
        : walkBehavior(walk), talkBehavior(talk), flyBehavior(fly), projectionBehavior(project) {}

    void walk()
    {
        walkBehavior->walk();
    }

    void talk()
    {
        talkBehavior->talk();
    }

    void fly()
    {
        flyBehavior->fly();
    }

    void projection()
    {
        projectionBehavior->projection();
    }

    ~Robot()
    {
        delete walkBehavior;
        delete talkBehavior;
        delete flyBehavior;
        delete projectionBehavior;
    }
};

int main()
{
    Robot *companion = new Robot(new NormalWalk(), new NormalTalk(), new NoFly(), new CompanionProjection());
    Robot *worker = new Robot(new NoWalk(), new NoTalk(), new NormalFly(), new WorkerProjection());

    cout << "Companion Robot:" << endl;
    companion->walk();
    companion->talk();
    companion->fly();
    companion->projection();

    cout << "\nWorker Robot:" << endl;
    worker->walk();
    worker->talk();
    worker->fly();
    worker->projection();

    delete companion;
    delete worker;
    return 0;
}