#include <iostream>
#include <string>
#include <stdexcept>
using namespace std;

template <typename T, int size>
class Vector {
private:
    T data[size];

public:
    Vector() {
        for (int i = 0; i < size; ++i) {
            data[i] = T();
        }
    }

    int getSize() const {
        return size;
    }

    T& operator[](int index) {
        if (index < 0 || index >= size) {
            throw out_of_range("Vector index out of range");
        }

        return data[index];
    }

    const T& operator[](int index) const {
        if (index < 0 || index >= size) {
            throw out_of_range("Vector index out of range");
        }

        return data[index];
    }

    template <typename U, int N>
    friend istream& operator>>(istream& in, Vector<U, N>& v);

    template <typename U, int N>
    friend ostream& operator<<(ostream& out, const Vector<U, N>& v);
};

template <typename U, int N>
istream& operator>>(istream& in, Vector<U, N>& v) {
    for (int i = 0; i < N; ++i) {
        in >> v.data[i];
    }

    return in;
}

template <typename U, int N>
ostream& operator<<(ostream& out, const Vector<U, N>& v) {
    for (int i = 0; i < N; ++i) {
        out << v.data[i] << " ";
    }

    return out;
}

int main() {
    Vector<int, 5> intArray;

    cout << "Input 5 integers:" << endl;
    cin >> intArray;

    cout << "intArray contains:" << endl;
    cout << intArray << endl;

    Vector<string, 7> stringArray;

    cout << "Input 7 words:" << endl;
    cin >> stringArray;

    cout << "stringArray contains:" << endl;
    cout << stringArray << endl;

    return 0;
}