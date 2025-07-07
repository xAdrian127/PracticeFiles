#include <iostream>

using namespace std;

class Person {
private:
    string name;
    int age;
public:
    // Constructor to initialize name and age
    Person(string tempstring, int tempage) : name(tempstring), age(tempage) {}
    // Member variables
    string getName() const { return name; }
    int getAge() const { return age; }
    void introduce() {
        cout << "Hi, I'm " << name << " and I'm " << age << " years old.\n";
    }
};

int main() {
    Person alice("Alice",21);

    // Create a pointer to alice
    Person* ptr = &alice;

    // Access members using the arrow operator (->)
    cout << "Name: " << ptr->getName() << endl;
    cout << "Age: " << ptr->getAge() << endl;

    // Call a member function using the arrow operator
    ptr->introduce();

    return 0;
}