//manacher's algo

#include <iostream>
#include <string>

using namespace std;

int main() {
    string str = "";
    cin >> str;
    /*
    srand(time(NULL));
    for (int i = 0; i < 5; i++) {
        str += char('a' + rand() % 2);
    }
    cout << str << endl;
    */

    int n = str.size();
    int* d1 = new int[n];
    int* d2 = new int[n];
    int left = 0, right = -1;
    for (int i = 0; i < n; i++) {
        if (i < right) {
            d1[i] = d1[left + right - i] > right - i + 1 ? d1[left + right - i] : right - i + 1;
        }
        while (i-d1[i] >= 0 && i+d1[i] < n && str[i-d1[i]] == str[i+d1[i]]) {
		    d1[i]++;
        }
        if (i + d1[i] - 1 > right) {
            left = i - d1[i] + 1;
            right = i + d1[i] - 1;
        }
    }

    left = 0, right = -1;
    for (int i = 0; i < n; i++) {
        if (i < right) {
            d2[i] = d2[left + right - i + 1] > right - i + 1 ? d2[left + right - i + 1] : right - i + 1;
        }
        while (i-d2[i]-1 >= 0 && i+d2[i] < n && str[i-d2[i]-1] == str[i+d2[i]]) {
		    d2[i]++;
        }
        if (i + d2[i] - 1 > right) {
            left = i - d2[i];
            right = i + d2[i] - 1;
        }
    }

/*
    for (char el : str) {
        cout << el << ' ';
    }
    cout << endl;
    for(int el : d1) {
        cout << el << ' ';
    }
    cout << endl;
    for (int el : d2) {
        cout << el << ' ';
    }
    cout << endl;
*/

    for (int maxLen = n; maxLen > 1; maxLen--) {
        if (maxLen % 2) {
            //even
            for (int middle = maxLen/2; middle < n - maxLen/2; middle++) {
                if (2*d1[middle]-1 < maxLen) {
                    cout << maxLen << endl;
                    return 0;
                }
            }
        }
        else {
            //odd
            for (int middle = maxLen/2; middle < n - maxLen/2 + 1; middle++) {
                if (2*d2[middle] < maxLen) {
                    cout << maxLen << endl;
                    return 0;
                }
            }
        }
    }    
    cout << -1 << endl;
}
