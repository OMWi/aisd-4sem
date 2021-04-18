//bfs

#include <iostream>
#include <queue>

using namespace std;

struct Cell {
    int moves;
    bool checked = false;
    int i;
    int j;
};


void print(Cell** cells, int n, int m);


int main() {
    int n, m, i, j;
    cin >> n >> m >> i >> j;
    if (i == 1 && j == 1) {
        cout << 0 << endl;
        return 0;
    }
    i--; j--;    
    int iMove[8] {2, 1, -1, -2, -2, -1, 1, 2};
    int jMove[8] {-1, -2, -2, -1, 1, 2, 2, 1};
    Cell** cells = new Cell*[n];
    for (int i = 0; i < n; i++) {
        cells[i] = new Cell[m];
        for (int j = 0; j < m; j++) {
            cells[i][j].i = i;
            cells[i][j].j = j;
        }
    }
    queue<Cell> cellsQueue;
    cells[0][0].checked = true;
    cells[0][0].moves = 0;
    cellsQueue.push(cells[0][0]);
    //print(cells, n, m);
    while (!cellsQueue.empty()) {
        Cell cur = cellsQueue.front();
        cellsQueue.pop();
        int moves = cur.moves + 1;

        for (int k = 0; k < 8; k++) {
            int iNext = cur.i + iMove[k];
            int jNext = cur.j + jMove[k];
            if (iNext < 0 || jNext < 0 || iNext >= n || jNext >= m) continue;
            if (!cells[iNext][jNext].checked) {                
                if (iNext == i && jNext == j) {
                    cout << cur.moves+1 << endl;
                    return 0;
                }                
                cells[iNext][jNext].moves = cur.moves+1;
                cells[iNext][jNext].checked = true;
                cellsQueue.push(cells[iNext][jNext]);
                //print(cells, n, m);
            }
        }
    }
    //print(cells, n, m);
    cout << "NEVAR" << endl;
}

void print(Cell** cells, int n, int m) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << cells[i][j].moves << ' ';
        }
        cout << endl;
    }
    cout << endl;
}