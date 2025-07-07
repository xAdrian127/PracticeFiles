#include <iostream>
using namespace std;

#include <algorithm> // For std::sort

// Utility function to print array
void printArray(int arr[], int n) {
    for (int i = 0; i < n; ++i)
        cout << arr[i] << " ";
    cout << endl;
}

// Bubble Sort
void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < n - i - 1; ++j) {
            if (arr[j] > arr[j + 1]) {
                cout << "Swapping " << arr[j] << " and " << arr[j + 1] << endl;
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                printArray(arr, n); // Print after each swap
            }else{
                cout << "No swap needed for " << arr[j] << " and " << arr[j + 1] << endl;
            }
        }cout<< "End of pass " << i + 1 << ": ";
        printArray(arr, n); // Print after each pass
        cout << "------------------------" << endl;
    }
}

// Selection Sort
void selectionSort(int arr[], int n) {
    for (int i = 0; i < n - 1; ++i) {
        int min_idx = i;
        for (int j = i + 1; j < n; ++j) {
            cout << "Comparing " << arr[j] << " with " << arr[min_idx] << endl;
            if (arr[j] < arr[min_idx]){
                min_idx = j;
                cout << "New minimum found: " << arr[min_idx] << endl;}
            else{
                cout << "No new minimum found, keeping " << arr[min_idx] << endl;
            }
        }
        cout << "Selecting minimum " << arr[min_idx] << " for position " << i << endl;
        cout << "Swapping " << arr[min_idx] << " and " << arr[i] << endl;
        int temp = arr[min_idx];
        arr[min_idx] = arr[i];
        arr[i] = temp;
        cout << "Array after selection: "<< "End of selection for index " << i << ": ";
        printArray(arr, n); // Print after each selection and swap
        cout << "------------------------" << endl;
    }
}

// Insertion Sort
void insertionSort(int arr[], int n) {
    for (int i = 1; i < n; ++i) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            cout<<"in while loop\n";
            arr[j + 1] = arr[j];
            --j;
            printArray(arr, n); // Print after each shift
        }
        cout<<"\nout of while loop\n";
        arr[j + 1] = key;
        printArray(arr, n); // Print after each insertion
    }
}

// Merge Sort helpers
void merge(int arr[], int l, int m, int r, int n) {
    int n1 = m - l + 1;
    int n2 = r - m;
    int* L = new int[n1];
    int* R = new int[n2];
    for (int i = 0; i < n1; ++i)
        L[i] = arr[l + i];
    for (int j = 0; j < n2; ++j)
        R[j] = arr[m + 1 + j];
    int i = 0, j = 0, k = l;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j])
            arr[k++] = L[i++];
        else
            arr[k++] = R[j++];
    }
    while (i < n1)
        arr[k++] = L[i++];
    while (j < n2)
        arr[k++] = R[j++];
    printArray(arr, n); // Print after each merge
    delete[] L;
    delete[] R;
}
void mergeSort(int arr[], int l, int r, int n) {
    if (l < r) {
        int m = l + (r - l) / 2;
        mergeSort(arr, l, m, n);
        mergeSort(arr, m + 1, r, n);
        merge(arr, l, m, r, n);
    }
}

// Quick Sort helpers
int partition(int arr[], int low, int high, int n) {
    int pivot = arr[high];
    int i = (low - 1);
    for (int j = low; j < high; ++j) {
        if (arr[j] < pivot) {
            ++i;
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
            printArray(arr, n); // Print after each swap
        }
    }
    int temp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = temp;
    printArray(arr, n); // Print after pivot swap
    return (i + 1);
}
void quickSort(int arr[], int low, int high, int n) {
    if (low < high) {
        int pi = partition(arr, low, high, n);
        quickSort(arr, low, pi - 1, n);
        quickSort(arr, pi + 1, high, n);
    }
}

int main() {
    int arr[] = {5, 2, 9, 1, 5, 6};
    int n = sizeof(arr) / sizeof(arr[0]);

    // Bubble Sort
    cout << "Bubble Sort process:" << endl;
    int arr1[6]; copy(arr, arr + n, arr1);
    cout << "Initial array: "; printArray(arr1, n);
    bubbleSort(arr1, n);
    cout << "Bubble Sort result: "; printArray(arr1, n);
    cout << "------------------------" << endl;

    // Selection Sort
    cout << "\nSelection Sort process:" << endl;
    int arr2[6]; copy(arr, arr + n, arr2);
    selectionSort(arr2, n);
    cout << "Selection Sort result: "; printArray(arr2, n);
    cout << "------------------------" << endl;

    // Insertion Sort
    cout << "\nInsertion Sort process:" << endl;
    int arr3[6]; copy(arr, arr + n, arr3);
    insertionSort(arr3, n);
    cout << "Insertion Sort result: "; printArray(arr3, n);

    // Merge Sort
    cout << "\nMerge Sort process:" << endl;
    int arr4[6]; copy(arr, arr + n, arr4);
    mergeSort(arr4, 0, n - 1, n);
    cout << "Merge Sort result: "; printArray(arr4, n);

    // Quick Sort
    cout << "\nQuick Sort process:" << endl;
    int arr5[6]; copy(arr, arr + n, arr5);
    quickSort(arr5, 0, n - 1, n);
    cout << "Quick Sort result: "; printArray(arr5, n);

    // STL Sort
    cout << "\nSTL Sort process:" << endl;
    int arr6[6]; copy(arr, arr + n, arr6);
    std::sort(arr6, arr6 + n);
    cout << "STL Sort result: "; printArray(arr6, n);

    return 0;
}