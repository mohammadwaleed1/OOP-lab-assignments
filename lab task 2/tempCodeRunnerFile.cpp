#include <iostream>
#include <vector>
using namespace std;

int main() {
    // Step 1: Declare a vector
    vector<int> numbers;
    numbers={1,2,3,4,5};

    // Step 2: Add elements to the vector
    numbers.push_back(10);
    numbers.push_back(20);
    numbers.push_back(30);

    cout << "Initial vector elements: ";
    for (int num : numbers) {
        cout << num << " ";
    }
    cout << endl;}