#include <iostream>
#include <vector>
#include <limits>

using namespace std;

struct Path {
    int vertex;
    int weight;
};

void print(vector<vector<Path>> matrix) {
    int i = 0;
    for (vector<Path> paths : matrix) {
        cout << i++ << ": ";
        for (Path elem : paths) {
            cout << elem.vertex << ' ' << elem.weight << ",  ";
        }
        cout << endl;
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<Path>> matrix(n);
    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        a--; b--;   
        matrix[a].push_back({b, c});
        matrix[b].push_back({a, c});
    }
    int start, end;
    cin >> start >> end;
    start--; end--;

    
    vector<long long> marks(n, std::numeric_limits<long long>::max());    
    vector<bool> visited(n, false);

    marks[start] = 0;
    for (int count = 0; count < n; count++) {  
        int cur;
        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                cur = i;
                break;
            }
        }    
        for (int i = cur + 1; i < n; i++) {
            if (!visited[i] && marks[i] < marks[cur] ) {
                cur = i;
            }
        }

        for (Path path : matrix[cur]) {
            long long newMark = marks[cur] + path.weight;
            if (newMark < marks[path.vertex]) {
                marks[path.vertex] = newMark;
            }
        }
        visited[cur] = true;
    }
    cout << marks[end] << endl;
}