#include <iostream>

using namespace std;

int main() {
    // 1. Declaring an array
    int arr[5] = {10, 20, 30, 40, 50};

    // 2. Declaring a pointer
    int* ptr;

    // 3. Pointing to the first element of the array
    ptr = arr; // Equivalent to ptr = &arr[0];

    // 4. Accessing array elements using the pointer
    cout << "Accessing array elements using pointer arithmetic:\n";
    for (int i = 0; i < 5; ++i) {
        cout << "Element " << i << ": " << *(ptr + i) << endl;
    }

    // 5. Modifying array elements using the pointer
    *(ptr + 2) = 99; // Changes arr[2] to 99

    cout << "\nArray after modification:\n";
    for (int i = 0; i < 5; ++i) {
        cout << "arr[" << i << "] = " << arr[i] << endl;
    }

    // 6. Demonstrating that array name is a pointer to its first element
    cout << "\nAddress of arr: " << arr << endl;
    cout << "Address stored in ptr: " << ptr << endl;
    cout << "Address of arr[0]: " << &arr[0] << endl;

    return 0;
}