#include <iostream>

long long merge(long long* arr, long long left, long long middle, long long right) {
    long long leftSize = middle - left + 1;
    long long rightSize = right - middle;
    long long* leftArr = new long long[leftSize];
    long long* rightArr = new long long[rightSize];
    for (long long i = 0; i < leftSize; i++) {
        leftArr[i] = arr[left+i];
    }
    for (long long i = 0; i < rightSize; i++) {
        rightArr[i] = arr[middle+i+1];
    }

    long long index = left, leftIndex = 0, rightIndex = 0;
    bool isInversion = false;
    long long numberOfInversions = 0;
    while (leftIndex < leftSize && rightIndex < rightSize) {
        if (leftArr[leftIndex] > rightArr[rightIndex]) {
            numberOfInversions += leftSize - leftIndex;
        }        
        arr[index++] = leftArr[leftIndex] < rightArr[rightIndex] ? leftArr[leftIndex++] : rightArr[rightIndex++];
    }
    
    while (leftIndex < leftSize) {
        arr[index++] = leftArr[leftIndex++];
    }
    while (rightIndex < rightSize) {
        arr[index++] = rightArr[rightIndex++];
    }
    delete[] leftArr;
    delete[] rightArr;
    return numberOfInversions;
}

long long mergeSort(long long* arr, long long left, long long right) {
    long long numberOfInversions = 0;
    if (left < right) {
        long long middle = left + (right - left)/2;
        numberOfInversions += mergeSort(arr, left, middle);
        numberOfInversions += mergeSort(arr, middle+1, right);
        numberOfInversions += merge(arr, left, middle, right);
    }
    return numberOfInversions;
}

int main() {
    long long size;
    std::cin >> size;
    long long* arr = new long long[size];
    for (long long i = 0; i < size; i++) {
        std::cin >> arr[i];
    }
    long long result = mergeSort(arr, 0, size-1);
    std::cout << result;
    return 0;
}
