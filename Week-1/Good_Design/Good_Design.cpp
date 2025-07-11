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

// Main app class
class RideSharingApp
{
private:
    vector<Ride *> rides;
    vector<Vehicle *> vehicles;
    Persistence *storage;

public:
    RideSharingApp(Persistence *store) : storage(store) {}
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
    string trackRideStatus(int index)
    {
        if (index < rides.size())
        {
            return rides[index]->getStatus();
        }
        return "Invalid ride index";
    }
    void saveRideDetails()
    {
        string content = "";
        for (auto ride : rides)
        {
            content += ride->getDetails() + "\n";
        }
        storage->save(content);
    }
    ~RideSharingApp()
    {
        for (auto ride : rides)
            delete ride;
        for (auto vehicle : vehicles)
            delete vehicle;
        delete storage;
    }
};

int main()
{
    Persistence *storage = new FileStorage();
    RideSharingApp app(storage);

    app.addVehicle(new BikeVehicle("Honda Bike"));
    app.addVehicle(new CarVehicle("Suzuki Mehran"));
    app.bookRide("Honda Bike", "Gulberg to Mall Road");
    cout << "Ride Status: " << app.trackRideStatus(0) << endl;
    app.saveRideDetails();
    return 0;
}
