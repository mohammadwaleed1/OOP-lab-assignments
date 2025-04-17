#include <iostream>
#include <string>

using namespace std;

class Flight;

class Passenger {
private:
    string id;
    string name;
    bool hasBooking = false;
    bool isUpgraded = false;

public:
    Passenger(string id, string name) : id(id), name(name) {}

    string getName() const { return name; }
    string getId() const { return id; }

    bool hasSeat() const { return hasBooking; }

    friend class Flight;

    void requestBooking(Flight& flight);
    void requestCancellation(Flight& flight);
    void requestUpgrade(Flight& flight);
};

class Flight {
private:
    string flightNumber;
    string departure;
    string arrival;
    int capacity;
    int bookedSeats;

public:
    Flight(string fn, string dep, string arr, int cap)
        : flightNumber(fn), departure(dep), arrival(arr), capacity(cap), bookedSeats(0) {}

    string getFlightInfo() const {
        return flightNumber + " | " + departure + " -> " + arrival + " | Seats Left: " + to_string(capacity - bookedSeats);
    }

    bool bookSeat(Passenger& passenger) {
        if (bookedSeats >= capacity) {
            cout << " No seats available on flight " << flightNumber << " for " << passenger.name << "\n";
            return false;
        }
        if (passenger.hasBooking) {
            cout << passenger.name << " already has a booking.\n";
            return false;
        }

        passenger.hasBooking = true;
        passenger.isUpgraded = false;
        bookedSeats++;
        cout << " Seat booked on flight " << flightNumber << " for " << passenger.name << "\n";
        return true;
    }

    bool cancelSeat(Passenger& passenger) {
        if (!passenger.hasBooking) {
            cout << passenger.name << " has no booking to cancel.\n";
            return false;
        }

        passenger.hasBooking = false;
        passenger.isUpgraded = false;
        bookedSeats--;
        cout << " Booking cancelled for " << passenger.name << " on flight " << flightNumber << "\n";
        return true;
    }

    bool upgradeSeat(Passenger& passenger) {
        if (!passenger.hasBooking) {
            cout << " Cannot upgrade: " << passenger.name << " has no booking.\n";
            return false;
        }
        if (passenger.isUpgraded) {
            cout << passenger.name << " is already upgraded.\n";
            return false;
        }

        passenger.isUpgraded = true;
        cout  << passenger.name << " has been upgraded on flight " << flightNumber << "\n";
        return true;
    }
};


void Passenger::requestBooking(Flight& flight) {
    flight.bookSeat(*this);
}

void Passenger::requestCancellation(Flight& flight) {
    flight.cancelSeat(*this);
}

void Passenger::requestUpgrade(Flight& flight) {
    flight.upgradeSeat(*this);
}

int main() {
    Flight f1("F101", "New York", "London", 2);
    Flight f2("F202", "Paris", "Tokyo", 1);

    Passenger p1("P001", "Alice");
    Passenger p2("P002", "Bob");
    Passenger p3("P003", "Charlie");

    cout << "\nFlight Info:\n";
    cout << f1.getFlightInfo() << "\n";
    cout << f2.getFlightInfo() << "\n";

    cout << "\n--- Booking Seats ---\n";
    p1.requestBooking(f1);
    p2.requestBooking(f1);
    p3.requestBooking(f1); 

    p3.requestBooking(f2); 

    cout << "\n--- Attempting Upgrades ---\n";
    p1.requestUpgrade(f1);
    p3.requestUpgrade(f1); 

    cout << "\n--- Cancelling & Rebooking ---\n";
    p2.requestCancellation(f1);
    p3.requestBooking(f1); 

    cout << "\nFinal Flight Info:\n";
    cout << f1.getFlightInfo() << "\n";
    cout << f2.getFlightInfo() << "\n";

    return 0;
}
