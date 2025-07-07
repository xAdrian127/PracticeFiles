#include <stdio.h> // For input/output operations
#include <stdlib.h> // For memory allocation and other utilities
#include <stdbool.h>
#include <string.h>

// Function declaration
int add(int a, int b);
// 6. Functions
int square(int x) {// Function to calculate the square of a number
    return x * x;
}




int main() {
    // This is a single-line comment

    /*
     * This is a multi-line comment.
     * It can span multiple lines.
     */

    // 1. Variable Declaration and Initialization
    int number = 10; // Integer variable
    float pi = 3.14; // Floating-point variable
    char name[] = "Ephraim"; // String (character array)

    // 2. Input and Output
    printf("Enter a number: ");
    scanf("%d", &number); // Taking input from the user
    printf("You entered: %d\n", number);

    // 3. Conditional Statements
    if (number > 0) {
        printf("The number is positive.\n");
    } else if (number < 0) {
        printf("The number is negative.\n");
    } else {
        printf("The number is zero.\n");
    }

    // 4. Loops
    printf("Counting from 1 to 5:\n");
    for (int i = 1; i <= 5; i++) {
        printf("%d ", i);
    }
    printf("\n");

    // 5. Arrays
    int numbers[] = {1, 2, 3, 4, 5}; // Static array
    printf("Array elements: ");
    for (int i = 0; i < 5; i++) {
        printf("%d ", numbers[i]);
    }
    printf("\n");


    printf("Square of 4: %d\n", square(4));

    // 7. Pointers
    int *ptr = &number; // Pointer to an integer
    printf("Address of number: %p, Value: %d\n", (void*)ptr, *ptr);

    // 8. Dynamic Memory Allocation
    int *dynamicArray = (int *)malloc(5 * sizeof(int)); // Allocate memory for 5 integers
    if (dynamicArray == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }
    for (int i = 0; i < 5; i++) {
        dynamicArray[i] = i + 1;
    }
    printf("Dynamic array elements: ");
    for (int i = 0; i < 5; i++) {
        printf("%d ", dynamicArray[i]);
    }
    printf("\n");
    free(dynamicArray); // Free allocated memory

    // Function call
    printf("Sum of 3 and 4: %d\n", add(3, 4));

    return 0;
}

// Function definition
int add(int a, int b) {
    return a + b;
}