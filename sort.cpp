#include<iostream>
#include<string>

// xuất mảng
void out(int a[], int n) {
    for (int i = 0; i < n; i++)
        std::cout << a[i] << " ";
}

// hoán vị 2 số
void swap(int &x, int &y) {
    int temp;
    temp = x;
    x = y;
    y = temp;
}

// sắp xếp đổi chỗ trực tiếp
void interchangeSort(int a[], int n) {
    for (int i = 0; i < n; i++)
        for (int j = i + 1; j < n; j++)
            if (a[i] > a[j])
                swap(a[i], a[j]);
}

// sắp xếp nổi bọt
void bubbleSort(int a[], int n) { 
    for (int i = 0; i < n; i++)
        for (int j = n - 1; j >= i; j--)
            if (a[i] > a[j]) 
                swap(a[i], a[j]);
}

// sắp xếp chèn
void insertionSort(int a[], int n) {
    int pos, x;
    for (int i = 1; i < n; i++) {
        x = a[i];
        pos = i;
        while (pos > 0 && x < a[pos-1]) {
            a[pos] = a[pos - 1];
            pos--;
        }
        a[pos] = x;
    }
}

// sắp xếp chọn
void selectionSort(int a[], int n) {
    int min;
    for (int i = 0; i < n; i++) {
        min = i;
        for (int j = i + 1; j < n; j++) {
            if (a[j] < a[min])
                min = j;
        }
        if (min != i)
            swap(a[i], a[min]);
    }
}

// sắp xếp nhanh
void quickSort(int a[], int left, int right) {
    int x = a[(left + right) / 2];
    int i = left;
    int j = right;
    do {
        while (a[i] < x)
            i++;
        while (a[j] > x)
            j--;
        if (i <= j) {
            swap(a[i], a[j]);
            i++;
            j--;
        }
    } while (i < j);
    if (left < j)
        quickSort(a, left, j);
    if (i < right)
        quickSort(a, i, right);
}

// sắp xếp trộn
void merge(int array[], int const left, int const mid, int const right) {
    int const subArrayOne = mid - left + 1;
    int const subArrayTwo = right - mid;
 
    // Create temp arrays
    int *leftArray = new int[subArrayOne],
         *rightArray = new int[subArrayTwo];
 
    // Copy data to temp arrays leftArray[] and rightArray[]
    for (int i = 0; i < subArrayOne; i++)
        leftArray[i] = array[left + i];
    for (int j = 0; j < subArrayTwo; j++)
        rightArray[j] = array[mid + 1 + j];
 
    int indexOfSubArrayOne = 0, // Initial index of first sub-array
        indexOfSubArrayTwo = 0; // Initial index of second sub-array
    int indexOfMergedArray = left; // Initial index of merged array
 
    // Merge the temp arrays back into array[left..right]
    while (indexOfSubArrayOne < subArrayOne && indexOfSubArrayTwo < subArrayTwo) {
        if (leftArray[indexOfSubArrayOne] <= rightArray[indexOfSubArrayTwo]) {
            array[indexOfMergedArray] = leftArray[indexOfSubArrayOne];
            indexOfSubArrayOne++;
        }
        else {
            array[indexOfMergedArray] = rightArray[indexOfSubArrayTwo];
            indexOfSubArrayTwo++;
        }
        indexOfMergedArray++;
    }
    // Copy the remaining elements of
    // left[], if there are any
    while (indexOfSubArrayOne < subArrayOne) {
        array[indexOfMergedArray] = leftArray[indexOfSubArrayOne];
        indexOfSubArrayOne++;
        indexOfMergedArray++;
    }
    // Copy the remaining elements of
    // right[], if there are any
    while (indexOfSubArrayTwo < subArrayTwo) {
        array[indexOfMergedArray] = rightArray[indexOfSubArrayTwo];
        indexOfSubArrayTwo++;
        indexOfMergedArray++;
    }
}

void mergeSort(int array[], int const begin, int const end) {
    if (begin >= end)
        return; // Returns recursively
 
    int mid = begin + (end - begin) / 2;
    mergeSort(array, begin, mid);
    mergeSort(array, mid + 1, end);
    merge(array, begin, mid, end);
}

int main() {
    int a[] = {2, 3, 4, 1, 5, 6};
    int n = sizeof(a) / sizeof(int);

    int b[] = {6, 5, 4, 3, 2, 1, 99};
    int m = sizeof(b) / sizeof(int);

    std::cout << "Array a: ";
    out(a, n);
    std::cout << "\nMerge Sort : ";
    mergeSort(a, 0, 5);
    out(a, n);

    // std::cout << "\n\nArray b: ";
    // out(b, m);
    // interchangeSort(b, m);
    // std::cout << "\nInterchange sort: ";
    // out(b, m);
    // return 0;
}