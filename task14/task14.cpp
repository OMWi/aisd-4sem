#include <iostream>

using namespace std;

int mod = 1000000007;

void matMul(long long** matrix1, long long** matrix2, long long*** res, int size) {
    long long** temp = new long long*[size];
    for (int i = 0; i < size; i++) {
        temp[i] = new long long[size];
        for (int j = 0; j < size; j++) {
            long long elem = 0;
            for (int k = 0; k < size; k++) {
                elem += ((matrix1[i][k] % mod) * (matrix2[k][j] % mod)) % mod;
            }
            elem %= mod;
            temp[i][j] = elem;
        }
    }
    for (int i = 0; i < size; i++) {
        delete[] (*res)[i];
    }
    delete[] *res;
    *res = temp;   
}

long long** binPow(long long** matrix, int size, int power) {
    long long** res = new long long*[size];
    for (int i = 0; i < size; i++) {
        res[i] = new long long[size];
        res[i][i] = 1;
    }
    while (power) {
        if (power & 1) {
            matMul(res, matrix, &res, size);
            power--;
        }
        else {
            matMul(matrix, matrix, &matrix, size);
            power >>= 1;
        }
    }
    return res;
}

int main() {  
    int n, m;
    cin >> n >> m;
    int u, v, l;
    cin >> u >> v >> l;
    u--; v--;
    if (!l) {
        if (u == v) {
            cout << 1 << endl;
        }
        else {
            cout << 0 << endl;
        }
        return 0;
    }    
    long long** matrix = new long long*[n];
    for (int i = 0; i < n; i++) {
        matrix[i] = new long long[n];
        for (int j = 0; j < n; j++) {
            matrix[i][j] = 0;
        }
    }
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        matrix[a][b]++;
        matrix[b][a]++;
    }
    long long** result = binPow(matrix, n, l);
    cout << result[u][v] << endl;
}