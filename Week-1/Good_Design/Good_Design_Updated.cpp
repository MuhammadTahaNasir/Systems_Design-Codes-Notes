#include <iostream>
#include <vector>
#include <fstream>
#include <string>
using namespace std;

// Abstract class for vehicles
class Vehicle
{
public:
    virtual string getDetails() = 0;
    virtual ~Vehicle() {}
};

// Concrete bike vehicle
class BikeVehicle : public Vehicle
{
private:
    string name;

public:
    BikeVehicle(string n) : name(n) {}
    string getDetails() override { return "Bike: " + name; }
};

// Concrete car vehicle
class CarVehicle : public Vehicle
{
private:
    string name;

public:
    CarVehicle(string n) : name(n) {}
    string getDetails() override { return "Car: " + name; }
};

// Ride class to manage ride details
class Ride
{
private:
    Vehicle *vehicle;
    string destination;
    string status;

public:
    Ride(Vehicle *v, string dest) : vehicle(v), destination(dest), status("Driver Assigned") {}
    void bookRide(Vehicle *v, string dest)
    {
        vehicle = v;
        destination = dest;
        status = "Driver Assigned";
    }
    string getStatus() { return status; }
    string getDetails() { return vehicle->getDetails() + " to " + destination + " (" + status + ")"; }
    ~Ride() { delete vehicle; }
};

// Abstract class for persistence
class Persistence
{
public:
    virtual void save(string content) = 0;
    virtual ~Persistence() {}
};

// Concrete file storage
class FileStorage : public Persistence
{
public:
    void save(string content) override
    {
        ofstream file("ride_details.txt");
        if (file.is_open())
        {
            file << content;
            file.close();
            cout << "Ride details saved successfully!" << endl;
        }
        else
        {
            cout << "Unable to open file!" << endl;
        }
    }
};

// Concrete database storage (placeholder)
class DBStorage : public Persistence
{
public:
    void save(string content) override
    {
        cout << "Saving to database: " << content << endl;
    }
};


class RideManager
{
private:
    vector<Ride *> rides;
    vector<Vehicle *> vehicles;

public:
    void addVehicle(Vehicle *vehicle)
    {
        vehicles.push_back(vehicle);
    }
    void bookRide(string vehicleType, string destination)
    {
        for (auto vehicle : vehicles)
        {
            if (vehicle->getDetails().find(vehicleType) != string::npos)
            {
                rides.push_back(new Ride(vehicle, destination));
                return;
            }
        }
        cout << "Vehicle not found!" << endl;
    }
    string getRideStatus(int index)
    {
        if (index < rides.size())
        {
            return rides[index]->getStatus();
        }
        return "Invalid ride index";
    }
    string getRideDetails()
    {
        string content = "";
        for (auto ride : rides)
        {
            content += ride->getDetails() + "\n";
        }
        return content;
    }
    ~RideManager()
    {
        for (auto ride : rides)
            delete ride;
        for (auto vehicle : vehicles)
            delete vehicle;
    }
};

class RideSharingApp
{
private:
    RideManager *rideManager;
    Persistence *storage;

public:
    RideSharingApp(RideManager *rm, Persistence *store) : rideManager(rm), storage(store) {}
    void addVehicle(Vehicle *vehicle) { rideManager->addVehicle(vehicle); }
    void bookRide(string vehicleType, string destination) { rideManager->bookRide(vehicleType, destination); }
    string trackRideStatus(int index) { return rideManager->getRideStatus(index); }
    void saveRideDetails() { storage->save(rideManager->getRideDetails()); }
    ~RideSharingApp()
    {
        delete rideManager;
        delete storage;
    }
};

int main()
{
    RideManager *rm = new RideManager();
    Persistence *storage = new FileStorage();
    RideSharingApp app(rm, storage);

    app.addVehicle(new BikeVehicle("Honda Bike"));
    app.addVehicle(new CarVehicle("Suzuki Mehran"));
    app.bookRide("Honda Bike", "Gulberg to Mall Road");
    cout << "Ride Status: " << app.trackRideStatus(0) << endl;
    app.saveRideDetails();
    return 0;
}
