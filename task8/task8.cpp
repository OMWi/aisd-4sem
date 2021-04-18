#include <iostream>
#include <string>

using namespace std;

bool isPalindrome(string str);

int main() {
    string str;
    cin >> str;
    bool oneSymb = true;
    for (int i = 0; i < str.size() - 1; i++) {
        if (str[i] != str[i+1]) {
            oneSymb = false;
            break;
        }
    }
    if (oneSymb) {
        cout << -1 << endl;
        return 0;
    }    
    if (isPalindrome(str)) {
        cout << str.size() - 1;
    }
    else {
        cout << str.size();
    }
    
}

bool isPalindrome(string str) {
    int n = str.size();
    for (int i = 0; i < n/2; i++) {
        if (str[i] != str[n - 1 - i]) return false;
    }
    return true;
}
