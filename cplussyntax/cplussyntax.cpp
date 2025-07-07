#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Function example
int add(int a, int b) {
    return a + b;
}

// Class example
class Person {
private:

public:
    string name;
    int age;

    Person(const string& n, int a) : name(n), age(a) {}
    void greet() {
        cout << "Hello, my name is " << name << endl;
    }
};

int main() {
    // Variable declaration
    int x = 5;
    double y = 3.14;
    string message = "Hello, C++!";

    // If-else statement
    if (x > 0) {
        cout << "x is positive" << endl;
    } else {
        cout << "x is not positive" << endl;
    }

    // For loop
    for (int i = 0; i < 3; ++i) {
        cout << "i = " << i << endl;
    }

    // While loop
    int count = 0;
    while (count < 2) {
        cout << "count = " << count << endl;
        ++count;
    }

    // Using a function
    int sum = add(2, 3);
    cout << "Sum: " << sum << endl;

    // Using a class
    Person p("Alice", 30);
    p.greet();

    // Using a vector
    vector<int> numbers = {1, 2, 3};
    for (int n : numbers) {
        cout << n << " ";
    }
    cout << endl;

    return 0;
}