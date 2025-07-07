#include <iostream>


/*
exercise from:
https://www.w3resource.com/c-programming-exercises/pointer/index.php
*/
using namespace std;

int main() {

    int m = 29;
    int* p = &m; // Pointer to m
    cout << "Address of m using p: " << p << endl;
    cout << "Value of m using p: " << *p << endl; // Dereferencing pointer p
    cout << "Address of p: " << &p << endl; 
    cout << "Address of m: " << &m << endl;
    cout << "Value of m: " << m << endl; 
    //change value of m using pointer p
    *p = 34; // Change value of m using pointer p
    cout << "New value of m using p: " << *p << endl; // Dereferencing pointer p
    cout << "New value of m: " << m << endl; // Value of m after change
    
    return 0;
}