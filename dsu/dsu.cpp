#include <iostream>
#include <time.h>

class DSU {
private:
    int* parent;

public:
    DSU(int size) {
        parent = new int[size];
    }

    void makeSet(int value) {
        parent[value] = value;
    }

    int find(int value) {
        if (value == parent[value]) {
            return value;
        }
        return parent[value] = find(parent[value]);
    }

    void unite(int x, int y) {
        x = find(x);
        y = find(y);
        if (rand() % 2) {
            std::swap(x, y);
        }
        parent[x] = y;
    }
};

int main() {
    srand(time(NULL));
    DSU test(5);
    test.makeSet(1);
    test.makeSet(2);
    test.makeSet(3);
    test.makeSet(4);
    test.unite(1, 2);
    test.unite(2, 3); 
}