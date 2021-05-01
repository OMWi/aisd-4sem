#include <iostream>
#include <string>

using namespace std;

void invert(char* symb);

int main() {
    string str;
    getline(cin, str);
    int len = str.size();

    int count;
    cin >> count;

    bool* ranges = new bool[count + 1];
    for (int i = 0; i < count; i++) {
        int left, right;
        cin >> left >> right;
        if (left > right) swap(left, right);
        left--;
        ranges[left] = !ranges[left];
        ranges[right] = !ranges[right];
        
    }

    bool requested = false;
    for (int i = 0; i < len; i++) {
        if (!requested) {
            if (ranges[i]) {
                requested = true;
                invert(&str[i]);
            }
        }
        else {
            if (ranges[i]) {
                requested = false;
            }
            else {
                invert(&str[i]);
            }
        }
    }

    cout << str << endl;
}

void invert(char* symb) {
    if (*symb >= 'a' && *symb <= 'z') {
        *symb -= 32;
    }
    else if (*symb >= 'A' && *symb <= 'Z') {
        *symb += 32;
    }
}
