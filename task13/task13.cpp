#include <iostream>

int* parent;

int find(int value) {
    if (value == parent[value]) {
        return value;
    }
    return parent[value] = find(parent[value]);
}

void make(int value) {
    parent[value] = value;
}

void unite(int x, int y) {
    x = find(x);
    y = find(y);
    if (rand() % 2) {
        std::swap(x, y);
    }
    parent[x] = y;
}

int getComp(int n) {
    bool* used = new bool[n];
    for (int i = 0; i < n; i++) {
        used[find(i)] = true;
    }
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (used[i]) count++;
    }
    return count;
}

int main() {
    int n, m;
    std::cin >> n >> m;
    parent = new int[n];
    for (int i = 0; i < n; i++) {
        make(i);
    }
    for (int i = 0; i < m; i++) {
        int u, v;
        std::cin >> u >> v;
        unite(--u, --v);
    }
    
    int comp = getComp(n);
    if (comp > 1) {
        std::cout << -1 << std::endl;
    }
    else {
        std::cout << m - n + 1 << std::endl;
    }
    
}