#include <iostream>
#include <string>
using namespace std;

// Abstract base class Robot
class Robot
{
public:
    virtual void walk()
    {
        cout << "Robot is walking normally" << endl;
    }

    virtual void talk()
    {
        cout << "Robot is talking normally" << endl;
    }

    virtual void fly()
    {
        cout << "Robot cannot fly" << endl;
    }

    virtual void projection() = 0; // Pure virtual function
    virtual ~Robot() {}            // Virtual destructor for proper cleanup
};

// Abstract class FlyableRobot
class FlyableRobot : public Robot
{
public:
    void fly() override
    {
        cout << "Flying with wings" << endl;
    }
};

// SparrowRobot class
class SparrowRobot : public FlyableRobot
{
public:
    void projection() override
    {
        cout << "Sparrow Robot projection: Bird-like and agile" << endl;
    }
};

// CrowRobot class
class CrowRobot : public FlyableRobot
{
public:
    void projection() override
    {
        cout << "Crow Robot projection: Dark and swift" << endl;
    }
};

int main()
{
    Robot *sparrow = new SparrowRobot();
    Robot *crow = new CrowRobot();

    cout << "Sparrow Robot:" << endl;
    sparrow->walk();
    sparrow->talk();
    sparrow->fly();
    sparrow->projection();

    cout << "\nCrow Robot:" << endl;
    crow->walk();
    crow->talk();
    crow->fly();
    crow->projection();

    delete sparrow;
    delete crow;
    return 0;
}