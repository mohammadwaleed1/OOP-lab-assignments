#include <iostream>

using namespace std;

class Car {
public:
    mutable int engineHorsepower;
    mutable int seatingCapacity;
    mutable int noOfSpeakers;

    Car(int engineHorsepower, int seatingCapacity, int noOfSpeakers)
        : engineHorsepower(engineHorsepower), seatingCapacity(seatingCapacity), noOfSpeakers(noOfSpeakers) {}

    void changeAttributes(int newEngineHorsepower, int newSeatingCapacity, int newNoOfSpeakers) const {
        engineHorsepower = newEngineHorsepower;
        seatingCapacity = newSeatingCapacity;
        noOfSpeakers = newNoOfSpeakers;
    }
        void displayAttributes() const {
        cout << "Engine Horsepower: " << engineHorsepower << endl;
        cout << "Seating Capacity: " << seatingCapacity << endl;
        cout << "Number of Speakers: " << noOfSpeakers << endl;
    }
};

int main() {
    Car myCar(150, 5, 6);
    cout << "Initial Car Attributes:" << endl;
    myCar.displayAttributes();
    cout << "\nChanging car attributes..." << endl;
    myCar.changeAttributes(200, 7, 8);
    cout << "\nUpdated Car Attributes:" << endl;
    myCar.displayAttributes();

    return 0;
}
