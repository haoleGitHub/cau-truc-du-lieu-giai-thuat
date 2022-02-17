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

int main() {
    int a[] = {2, 3, 4, 1, 5, 6};
    int n = sizeof(a) / sizeof(int);

    int b[] = {6, 5, 4, 3, 2, 1, 99};
    int m = sizeof(b) / sizeof(int);

    std::cout << "Array a: ";
    out(a, n);
    std::cout << "\nQuick Sort : ";
    quickSort(a, 0, 5);
    out(a, n);

    std::cout << "\n\nArray b: ";
    out(b, m);
    interchangeSort(b, m);
    std::cout << "\nInterchange sort: ";
    out(b, m);
    return 0;
}