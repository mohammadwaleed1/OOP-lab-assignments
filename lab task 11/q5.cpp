#include <iostream>
#include <vector>
#include <exception>

using namespace std;

class StackUnderflowException : public exception {
public:
    const char* what() const noexcept override {
        return "Stack underflow: Attempted to access an element from an empty stack.";
    }
};

template<typename T>
class Stack {
private:
    vector<T> data;

public:
    void push(const T& value) {
        data.push_back(value);
    }

    void pop() {
        if (data.empty())
            throw StackUnderflowException();
        data.pop_back();
    }

    T& top() {
        if (data.empty())
            throw StackUnderflowException();
        return data.back();
    }

    const T& top() const {
        if (data.empty())
            throw StackUnderflowException();
        return data.back();
    }

    bool isEmpty() const {
        return data.empty();
    }

    size_t size() const {
        return data.size();
    }
};
