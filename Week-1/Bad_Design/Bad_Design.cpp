#include <iostream>
#include <vector>
#include <fstream>
#include <string>
using namespace std;

class RideSharingApp {
private:
    vector<string> vehicles; // Stores vehicle names
    vector<string> rides;   // Stores ride details (vehicle + destination)
    string rideStatus;      // Current ride status

public:
    void addVehicle(string vehicle) {
        vehicles.push_back(vehicle);
    }

    void bookRide(string vehicleType, string destination) {
        // Simple check if vehicle exists
        for (const auto& vehicle : vehicles) {
            if (vehicle == vehicleType) {
                rides.push_back(vehicleType + " to " + destination);
                rideStatus = "Driver Assigned";
                return;
            }
        }
        rideStatus = "Vehicle Not Found";
    }

    string trackRideStatus() {
        return rideStatus;
    }

    void saveRideDetails() {
        ofstream file("ride_details.txt");
        if (file.is_open()) {
            for (const auto& ride : rides) {
                file << ride << "\n";
            }
            file.close();
            cout << "Ride details saved successfully!" << endl;
        } else {
            cout << "Unable to open file!" << endl;
        }
    }
};

int main() {
    RideSharingApp app;
    app.addVehicle("Honda Bike");
    app.addVehicle("Suzuki Mehran");
    app.bookRide("Honda Bike", "Gulberg to Mall Road");
    cout << "Ride Status: " << app.trackRideStatus() << endl;
    app.saveRideDetails();
    return 0;
}
