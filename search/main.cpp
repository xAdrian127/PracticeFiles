#include <iostream>
#include <algorithm>
using namespace std;

// Simple linear search implementation
void linearSearch(int arr[], int size, int key) {
    for (int i = 0; i < size; ++i) {
        cout << "Checking index " << i << ": " << arr[i] << endl; // Debug output
        // If the current element matches the key, print the index and return
        if (arr[i] == key) {
            cout << "Found at index " << i << endl;
            return;
        }
    }
    cout << "Not found" << endl;
}
void stlFind(int arr[], int size, int key) {
    // Using STL find function
    auto it = find(arr, arr + size, key);
    if (it != arr + size) {
        cout << "Found at index " << it - arr << endl;
    } else {
        cout << "Not found" << endl;
    }
}
void binary_search_aglorithm(int arr[], int size, int key) {
    // Using STL binary search function
   auto it = std::lower_bound(arr, arr + size, key);
if (it != arr + size && *it == key) {
    cout << "Found using binary search at index " << (it - arr) << endl;
} else {
    cout << "Not found using binary search" << endl;
}
auto it2 =std::upper_bound(arr, arr + size, key);
    if (it2 != arr + size && *(it2 - 1) == key) {
        cout << "Found using binary search at index " << (it2 - arr - 1) << endl;
    } else {
        cout << "Not found using binary search" << endl;
    }           
}


int main() {

    int arr[] = {10, 20, 30, 40, 50, 60}; // Sample array
    int key = 40;                                   // target key to search for
    int size = sizeof(arr) / sizeof(arr[0]); // Calculate size of the array
    cout <<"linear search function: "<<endl;
    linearSearch(arr, size, key);                   // Call linear search function
    cout << "------------------------" << endl;
    cout << "STL find function: " << endl;
    stlFind(arr, size, key);                        // Call STL find function
    cout << "------------------------" << endl;
    //binary search requires sorted array
    cout << "Binary search function: " << endl;
    binary_search_aglorithm(arr, size, key);
    cout << "------------------------" << endl;
    return 0;
}
