#include <iostream>

class BadTypeException {
public:
    const char* what() const {
        return "BadTypeException: Incorrect type requested.";
    }
};

class Placeholder {
public:
    virtual ~Placeholder() {}
    virtual Placeholder* clone() const = 0;
};

template<typename T>
class Holder : public Placeholder {
public:
    T value;

    Holder(const T& val) : value(val) {}

    Placeholder* clone() const override {
        return new Holder<T>(value);
    }
};

class TypeSafeContainer {
private:
    Placeholder* data;

public:
    TypeSafeContainer() : data(nullptr) {}

    TypeSafeContainer(const TypeSafeContainer& other) {
        data = other.data ? other.data->clone() : nullptr;
    }

    TypeSafeContainer& operator=(const TypeSafeContainer& other) {
        if (this != &other) {
            delete data;
            data = other.data ? other.data->clone() : nullptr;
        }
        return *this;
    }

    ~TypeSafeContainer() {
        delete data;
    }

    template<typename T>
    void store(const T& val) {
        delete data;
        data = new Holder<T>(val);
    }

    template<typename T>
    T get() const {
        Holder<T>* ptr = dynamic_cast<Holder<T>*>(data);
        if (!ptr) {
            throw BadTypeException();
        }
        return ptr->value;
    }
};
