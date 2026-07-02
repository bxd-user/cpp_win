#include <iostream>
#include <stdexcept>
using namespace std;

template <typename elementType, int numberOfElements>
class Array {
private:
    elementType data[numberOfElements];

public:
    Array() {
        for (int i = 0; i < numberOfElements; ++i) {
            data[i] = elementType();
        }
    }

    int getSize() const {
        return numberOfElements;
    }

    elementType& operator[](int index) {
        if (index < 0 || index >= numberOfElements) {
            throw out_of_range("Array index out of range");
        }

        return data[index];
    }

    const elementType& operator[](int index) const {
        if (index < 0 || index >= numberOfElements) {
            throw out_of_range("Array index out of range");
        }

        return data[index];
    }

    void print() const {
        for (int i = 0; i < numberOfElements; ++i) {
            cout << data[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    Array<int, 5> intArray;

    for (int i = 0; i < intArray.getSize(); ++i) {
        intArray[i] = i + 1;
    }

    cout << "intArray: ";
    intArray.print();

    Array<double, 3> doubleArray;
    doubleArray[0] = 1.1;
    doubleArray[1] = 2.2;
    doubleArray[2] = 3.3;

    cout << "doubleArray: ";
    doubleArray.print();

    try {
        cout << intArray[10] << endl;
    }
    catch (const out_of_range& e) {
        cout << "Exception: " << e.what() << endl;
    }

    return 0;
}