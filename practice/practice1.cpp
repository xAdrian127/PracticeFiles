#include <iostream>
#include <string>
#include <math.h>
using namespace std;

/*
Q3. Write a Program to Print the ASCII Value of a Character.
In C++, each character has some ASCII value associated with it. In this problem, we have to print the ASCII value of the character in the console.

For Example,

Input: Character = A
Output: ASCII Value of 'A' = 65
*/
void printASCIIValue() {
    char character;
    cout << "Enter a character: ";
    cin >> character;
    // Print the ASCII value of the character
    cout << "ASCII Value of '" << character << "' = " << int(character) << endl<< endl;
}

/*
Q10. Write a Program to Check Whether a Number Is Prime or Not.
The number can be prime or non-prime based on the number of its factors. In this program, we have to check whether the given number is prime or not and print the result on the console screen.

For Example,

Input: Number to Check = 29
Output: 29 is a prime number.
*/
void checkPrime() {
    int number;
    cout << "Enter a number to check = ";
    cin >> number;
    if (number <= 1) {
        cout << number << " is not a prime number." << endl;
        return;
    }

    for (int i = 2; i * i <= number; i++) {
        if (number % i == 0) {
            cout << number << " is not a prime number." << endl;
            return;
        }
    }
    cout << number << " is a prime number." << endl;
}

/*
Q13. Write a Program to Reverse a Sentence Using Recursion.
In this program, you have to simply reverse the sentence stored as a string.

For Example,

Input: Sentence = "Quick brown fox";
Output: xof nworb kciuQ
*/
void reverse(string sentence) {
    if (sentence.empty()) {
        return;
    }
    cout << sentence.back();
    // Remove the last character and call the function recursively
    reverse(sentence.substr(0, sentence.size() - 1));
}
void reverseSentence(){
    string sentence;
    cout << "Input: Sentence = ";
    getline(cin, sentence); // Use getline to read the entire line including spaces
    cout << "Output: ";
    reverse(sentence);
    cout << endl;

}

/*
The Fibonacci Series is a mathematical sequence in which the next number is the sum of the last two numbers in the sequence. In this program, you will have to print the Nth number in the sequence using recursion.

For Example,

Input: N = 12
Output: 144 
*/
/* fubini: 
N TOTAL NUMBER IN LINE 97   PROCESS(LINE 101/99)
0 0     fibnoacci(0)        return 0; // Base case: fibonacci(0) = 0
1 1     fibnoacci(1)        return 1; // Base case: fibonacci(1) = 1
2 1     fibonacci(2)        fibonacci(1) + fibonacci(0) = 1 + 0 = 1 
3 2     fibonacci(3)        fibonacci(2) + fibonacci(1) = fibonacci(1) + fibonacci(0) + 1 = 1 + 0 = 1 + 1 = 2
4 3                         fibonacci(3) + fibonacci(2) = fibonacci(2) + fibonacci(1) + fibonacci(1) + fibonacci(0) = 1 + 1 + 0 = 2 + 1 = 3
5 5                         fibonacci(4) + fibonacci(3) = fibonacci(3) + fibonacci(2) + fibonacci(2) + fibonacci(1) = 2 + 1 + 1 + 0 = 3 + 2 = 5
6 8                         fibonacci(5) + fibonacci(4) = fibonacci(4) + fibonacci(3) + fibonacci(3) + fibonacci(2) = 3 + 2 + 2 + 1 = 5 + 3 = 8
7 13    
8 21   

*/
int fibonacci(int n) {
    if (n <= 1) {
        return n; // Base case: return n if n is 0 or 1
    }
    return fibonacci(n - 1) + fibonacci(n - 2);
}
void fibonacci(){
    cout << "Output: " << fibonacci(3) << endl; 
} 
/*
Q21. Write a Program to Compute the Sum of Diagonals of a Matrix.(2D Array)(square matrix)
In this problem, you have to calculate the Sum of both the diagonal elements of a matrix. Matrix are generally represented as 2D arrays.
*/
void sum_of_maxtrix_diagonal(){
    int example_matrix[3][3] = {
        {1, 2, 3},  //[0][0], [0][1], [0][2]
        {4, 5, 6},  // [1][0], [1][1], [1][2]
        {7, 8, 9}  // [2][0], [2][1], [2][2]
    };
    int primarydiagonal = 0;
    int secondarydiagonal = 0;
    int n = sqrt(sizeof(example_matrix)/4); // Size of the matrix (n x n)
    for (int i = 0; i < n; i++) {
        primarydiagonal += example_matrix[i][i]; // Sum of primary diagonal
        secondarydiagonal += example_matrix[i][n-1-i]; // Sum of secondary diagonal
    }
    cout << "Sum of primary diagonal: " << primarydiagonal << endl;
    cout << "Sum of secondary diagonal: " << secondarydiagonal << endl;
}

/*
Q22. Write a Program to Rotate the Elements of a Matrix.
We can rotate the matrix in two ways: clockwise and anticlockwise. In this problem, you have to rotate the elements of the matrix in the clockwise direction for K number of times.
*/
void rotateMatrix(){
    int matrix[3][3] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };
    int n = 3; // Size of the matrix (n x n)
    int k = 1; // Number of rotations
    for (int r = 0; r < k; r++) {
        // Rotate the matrix clockwise
        int temp[3][3];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                temp[j][n - 1 - i] = matrix[i][j];
            }
        }
        // Copy the rotated matrix back to the original matrix
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                matrix[i][j] = temp[i][j];
            }
        }
    }
    cout << "Rotated Matrix: " << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

int main(){

    // printASCIIValue();
    // checkPrime();
    // reverseSentence();
    // fibonacci();
    // sum_of_maxtrix_diagonal();
    rotateMatrix();

    return 0;   

}