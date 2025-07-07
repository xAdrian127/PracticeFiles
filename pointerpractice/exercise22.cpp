#include <iostream>


using namespace std;

int main() {
    char str[50]; // Declare a character array to hold the string
    int len=0;
    cout << "Enter a string (max 49 characters): ";
    cin>> str; // Read a string from standard input
    while(*(str + len) != '\0') { // Calculate length of the string
        len++;
    }
    cout <<"value of len is: "<<len<<endl;
    cout<<"reverse string is: ";

    for(int i = len-1; i > -1; i--) {
        cout << *(str + i);
    }

    return 0;
}