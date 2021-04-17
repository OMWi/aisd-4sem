#include <iostream>

using namespace std;

int abs(int x) {
	if (x < 0) return -x;
	return x;
}

int main() {
	int n, m;
	int x1, y1, x2, y2;
	cin >> n >> m;
	cin >> x1 >> y1 >> x2 >> y2;
	if (abs(x1 - x2) == abs(y1 - y2)) cout << "NO";
	else cout << "YES";
}