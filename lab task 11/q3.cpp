#include <iostream>
#include <exception>

using namespace std;

class ArrayIndexOutOfBounds : public exception {
public:
    const char* what() const noexcept override {
        return "Array index out of bounds.";
    }
};

template<typename T>
class SafeArray {
private:
    T* arr;
    size_t size;

public:
    SafeArray(size_t n) : size(n) {
        arr = new T[size];
    }

    ~SafeArray() {
        delete[] arr;
    }

    SafeArray(const SafeArray& other) : size(other.size) {
        arr = new T[size];
        for (size_t i = 0; i < size; ++i)
            arr[i] = other.arr[i];
    }

    SafeArray& operator=(const SafeArray& other) {
        if (this != &other) {
            delete[] arr;
            size = other.size;
            arr = new T[size];
            for (size_t i = 0; i < size; ++i)
                arr[i] = other.arr[i];
        }
        return *this;
    }

    size_t length() const {
        return size;
    }

    T& operator[](int index) {
        if (index < 0 || static_cast<size_t>(index) >= size)
            throw ArrayIndexOutOfBounds();
        return arr[index];
    }

    const T& operator[](int index) const {
        if (index < 0 || static_cast<size_t>(index) >= size)
            throw ArrayIndexOutOfBounds();
        return arr[index];
    }
};
