#include <iostream>
#include <vector>

using namespace std;

int mod = 10000007;
vector<vector<pair<int, int>>> graph;
int n;
long long sum = 0;

int dfs(int node, int parent) {
    int wayCount = 1;
    for (int i = 0; i < graph[node].size(); i++) {
        int nextNode = graph[node][i].first;
        if (nextNode != parent) {
            long long countNext = dfs(nextNode, node);
            sum = (sum + (countNext * (n - countNext) * graph[node][i].second * 2)) % mod;
            wayCount += countNext;
        }
    }
    return wayCount;
}

int main() {
    cin >> n;    
    graph.
    for (int i = 0; i < n -1; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        a--; b--;
        graph[a].push_back(make_pair(b, c));
        graph[b].push_back(make_pair(a, c));
    }
    long result = dfs(1, 0);
    cout << sum << endl;
}