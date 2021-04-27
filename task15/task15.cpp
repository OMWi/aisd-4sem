#include <iostream>

int main() {
    int size;
    std::cin >> size;
    int* arr = new int[size];
    for (int i = 0; i < size; i++) {
        std::cin >> arr[i];
    }

    int count = 0;
    int max = arr[0];
    for (int i = 1; i < size; i++) {
        if (arr[i] > max) {
            count += arr[i] - max;
            max = arr[i];
        }       
        else {
            if (arr[i] < arr[i-1]) {
                count += arr[i-1] - arr[i];
            }
        }
    }   
    std::cout << count; 
    delete arr;
}