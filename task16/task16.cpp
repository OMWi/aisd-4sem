#include <iostream>
#include <string>

using namespace std;

void sort(string* str, int startIndex) {
    int size = (*str).size();
    for (int current = startIndex; current < size - 1; current++) {
        for (int next = current; next < size; next++) {
            if ((*str)[current] > (*str)[next]) {
                swap((*str)[current], (*str)[next]);
            }
        }
    }
}

int main() {
    int num;
    cin >> num;
    string str = to_string(num);
    int size = str.size();
    
    
    bool isFound = false;
    int leftChangeIndex = -1, rightChangeIndex = -1;
    for (int i = size - 1; i > 0; i--) {
        for (int j = i - 1; j > leftChangeIndex; j--) {
            if (str[j] < str[i]) {
                if (leftChangeIndex < j) {
                    leftChangeIndex = j;
                    rightChangeIndex = i;
                }
                isFound = true;
                break;
            }
        }     
    }

    if (isFound) {
        swap(str[leftChangeIndex], str[rightChangeIndex]);
        sort(&str, leftChangeIndex + 1);
        cout << str << endl;
    }
    else {
        cout << -1 << endl;
    }
    
}