#include <iostream>
#include <vector>
#include <string>
#include <algorithm> // Important for remove

using namespace std;

// Observer Interface
class IObserver
{
public:
    virtual void update() = 0;
    virtual ~IObserver() {}
};

// Observable Interface
class IObservable
{
public:
    virtual void add(IObserver *observer) = 0;
    virtual void remove(IObserver *observer) = 0;
    virtual void notify() = 0;
    virtual ~IObservable() {}
};

// Concrete Observable (YouTube Channel)
class ConcreteObservable : public IObservable
{
private:
    vector<IObserver *> observers;
    string channelName;
    string state;

public:
    ConcreteObservable(string name) : channelName(name) {}

    void add(IObserver *observer) override
    {
        if (find(observers.begin(), observers.end(), observer) == observers.end())
        {
            observers.push_back(observer);
            cout << "Subscribed to " << channelName << endl;
        }
    }

    void remove(IObserver *observer) override
    {
        // Even with 'using namespace std;', use std::remove to avoid ambiguity
        observers.erase(std::remove(observers.begin(), observers.end(), observer), observers.end());
        cout << "Unsubscribed from " << channelName << endl;
    }

    void notify() override
    {
        for (IObserver *observer : observers)
        {
            observer->update();
        }
    }

    void setState(string newState)
    {
        state = newState;
        cout << channelName << " uploaded: " << state << endl;
        notify();
    }

    string getState()
    {
        return "New video: " + state;
    }
};

// Concrete Observer (Subscriber)
class ConcreteObserver : public IObserver
{
private:
    string name;
    ConcreteObservable *observable;

public:
    ConcreteObserver(string n, ConcreteObservable *obs) : name(n), observable(obs) {}

    void update() override
    {
        cout << "Hey " << name << ", " << observable->getState() << endl;
    }
};

// Main function
int main()
{
    ConcreteObservable channel("TechBit");
    ConcreteObserver user1("Ali", &channel);
    ConcreteObserver user2("Sana", &channel);

    channel.add(&user1);
    channel.add(&user2);

    channel.setState("Observer Pattern Tutorial");
    channel.remove(&user1);
    channel.setState("Decorator Pattern Tutorial");

    return 0;
}
