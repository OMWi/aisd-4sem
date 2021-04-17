#include <vector>
#include <iostream>
#include <string>
#include <time.h>

using namespace std;

void print(vector<vector<int>> graph);
void print(vector<int> vect);
int getCount(vector<vector<int>> graph);
int testCount(vector<vector<int>> graph);
void dfs(int vertex, bool* used, vector<vector<int>> graph);

void test() {
    int n = 3000;
    int m = 3000;
    cout << "size " << n << ' ' << m << endl;
    vector<vector<int>> graph(n);
    for (int i = 0; i < m; i++) {
        int u = rand() % n;
        int v = rand() % n;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    cout << "Start calculation" << endl;
    int count = getCount(graph);
    cout << count << endl;

}

int main() {
    test();
    /*
    int n, m;
    cin >> n >> m;
    vector<vector<int>> graph(n);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        u--; v--;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    int count = getCount(graph);
    cout << count - 1 << endl;
    */
}

void dfs(int vertex, bool* used, vector<vector<int>> graph) {
    used[vertex] = true;
    int len = graph[vertex].size();
    for (int i = 0; i < len; i++) {
        if (!used[graph[vertex][i]]) {
            dfs(graph[vertex][i], used, graph);
        }
    }
}

int getCount(vector<vector<int>> graph) {
    int count = 0;
    clock_t start = clock();
    count = 0;
    bool* used = new bool[graph.size()];
    for (int i = 0; i < graph.size(); i++) {
        if (!used[i]) {
            dfs(i, used, graph);
            count++;
        }
    }
    delete used;
    clock_t end = clock();
    cout << "Elapsed time = " << (float)(end - start) / CLOCKS_PER_SEC  << endl; 
    return count;
}

int testCount(vector<vector<int>> graph) {
    int count = 0;
    int size = graph.size();
    for (int i = 0; i < size; i++) {
        if () {
            count++;
        }
    })
}

void print(vector<vector<int>> graph) {
    int i = 0;
    for (vector<int> x : graph) {
        cout << i++ << ": ";
        print(x);
    }
}

void print(vector<int> vect) {
    for (int elem : vect) {
        cout << elem << ' ';
    }
    cout << '\n';
}
