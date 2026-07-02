#include <iostream>
#include <string>
using namespace std;

template <typename T>
bool isEqualTo(const T& a, const T& b) {
    return a == b;
}

class Complex {
private:
    double real;
    double imag;

public:
    Complex(double r = 0.0, double i = 0.0)
        : real(r), imag(i) {}

    bool operator==(const Complex& other) const {
        return real == other.real && imag == other.imag;
    }

    bool operator!=(const Complex& other) const {
        return !(*this == other);
    }

    friend ostream& operator<<(ostream& out, const Complex& c) {
        out << "(" << c.real << ", " << c.imag << ")";
        return out;
    }
};

int main() {
    cout << boolalpha;

    cout << "int equal: "
         << isEqualTo(10, 10) << endl;

    cout << "double equal: "
         << isEqualTo(1.1, 2.2) << endl;

    cout << "char equal: "
         << isEqualTo('a', 'a') << endl;

    string s1 = "hello";
    string s2 = "world";
    cout << "string equal: "
         << isEqualTo(s1, s2) << endl;

    Complex c1(1.0, 2.0);
    Complex c2(1.0, 2.0);
    Complex c3(3.0, 4.0);

    cout << "c1 = " << c1 << endl;
    cout << "c2 = " << c2 << endl;
    cout << "c3 = " << c3 << endl;

    cout << "complex equal c1/c2: "
         << isEqualTo(c1, c2) << endl;

    cout << "complex equal c1/c3: "
         << isEqualTo(c1, c3) << endl;

    return 0;
}