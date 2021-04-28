#include <iostream>
#include <time.h>

void print(int* arr, int size) {
    for (int i = 0; i < size; i++) {
        std::cout << arr[i] << ' ';
    }
    std::cout << std::endl;
}


void merge(int* arr, int left, int middle, int right) {
    int leftSize = middle - left + 1;
    int rightSize = right - middle;
    int* leftArr = new int[leftSize];
    int* rightArr = new int[rightSize];
    for (int i = 0; i < leftSize; i++) {
        leftArr[i] = arr[left+i];
    }
    for (int i = 0; i < rightSize; i++) {
        rightArr[i] = arr[middle+i+1];
    }

    int index = left, leftIndex = 0, rightIndex = 0;
    while (leftIndex < leftSize && rightIndex < rightSize) {
        arr[index++] = leftArr[leftIndex] < rightArr[rightIndex] ? leftArr[leftIndex++] : rightArr[rightIndex++];
    }
    
    while (leftIndex < leftSize) {
        arr[index++] = leftArr[leftIndex++];
    }
    while (rightIndex < rightSize) {
        arr[index++] = rightArr[rightIndex++];
    }
    print(arr+left, leftSize + rightSize);
    std::cout << std::endl;
    delete[] leftArr;
    delete[] rightArr;
}

void mergeSort(int* arr, int left, int right) {
    if (left < right) {
        int middle = left + (right - left)/2;
        mergeSort(arr, left, middle);
        mergeSort(arr, middle+1, right);
        merge(arr, left, middle, right);
    }
}

int main() {
    srand(time(nullptr));
    int size;
    std::cin >> size;
    int* arr = new int[size];
    for (int i = 0; i < size; i++) {
        arr[i] = rand() % 21 - 10;
    }
    //
    print(arr, size);

    mergeSort(arr, 0, size-1);
    std::cout << std::endl;
    print(arr, size);



    delete[] arr;
}