#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


class Task {
    int size, numbersAmount;
    long long* arr;
public:
    int mod;
    Task(int size, int numbersAmount, long long* arr) {
        this->size = size;
        this->numbersAmount = numbersAmount;
        this->arr = arr;
        mod = 1000000007;
    }

    long long getResult() {
        sort(arr, arr+size);
        int left = 0, right = size - 1;
        int count = 0;
        long long result = 1;

        if (numbersAmount == 1) return arr[right] % mod;
        if (arr[right] < 0 && numbersAmount % 2 == 1) {
            for (int i = right; i >= size - numbersAmount; i--) {
                result = ((result % mod) * (arr[i] % mod)) % mod;
            }
            return result;
        }
        if (numbersAmount % 2 == 1 && arr[right] > 0) {
            result = arr[right--] % mod;
            count++;            
        }
        
        while (count < numbersAmount) { 
            if (numbersAmount - count == 1) {
                result = ((result % mod) * (arr[right] % mod)) % mod;
                break;
            }    
            if (numbersAmount - count == 3) {
                long long mul1 = arr[left] * arr[left+1] * arr[right];
                long long mul2 = arr[right] * arr[right-1] * arr[right-2];
                long long mul = (mul1 > mul2) ? mul1 : mul2;
                result = ((result % mod) * (mul % mod)) % mod;
                break;
            } 
            long long leftMul = arr[left] * arr[left+1];
            long long rightMul = arr[right] * arr[right-1];
            if (leftMul > rightMul) {
                result = ((result % mod) * (leftMul % mod)) % mod;
                left += 2;
            }
            else {
                result = ((result % mod) * (rightMul % mod)) % mod;
                right -= 2;
            }
            count += 2;
        }
        return result;
    }

    void print() {
        cout << "[" << size << ", " << numbersAmount << "]: ";
        for (int i = 0; i < size; i++) {
            cout << arr[i] << ' ';
        }
        cout << endl;
    }

};

int main() {
    int n, k;
    cin >> n >> k;
    long long* arr = new long long[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    Task* task = new Task(n, k, arr);  
    long long res = task->getResult();
    while (res < 0) res += task->mod;
    cout << res << endl;
}