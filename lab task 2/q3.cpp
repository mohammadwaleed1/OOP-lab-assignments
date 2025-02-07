#include <iostream>
using namespace std;

int main() {
    int size = 5;
    int *arr = new int[size];
    int count = 0;
    int num;
    cout<<"enter element to add in array:";
    cin>>num;
    for (int i = 0; i < num; i++) {
        if (count == size) {
            size *= 2;
            vector<int>arr(size);
        }
        arr[count++] = i + 1;
    }
    for (int i = 0; i < num; i++) {
        cout << arr[i] << " ";
    }

    delete[] arr; 
    return 0;
}
