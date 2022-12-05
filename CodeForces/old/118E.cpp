#include<iostream>
#include<vector>
using namespace std;

const int MAX = 1e5 + 2;
const int EDGE_MAX = 3e5 + 2;
int tin[MAX], low[MAX], parent[MAX], timer, n, m, a, b;
bool visited[MAX];
vector<int> g[MAX];

void dfs(int u, int p = -1) {
    visited[u] = true;
    tin[u] = low[u] = timer++;
    parent[u] = p;

    for(int to : g[u]) {
        if(to == p) continue;
        if(visited[to]) 
            low[u] = min(low[u], tin[to]);
        else {
            dfs(to, u);
            low[u] = min(low[u], low[to]);
            if(low[to] > tin[u]) {
                cout << 0 << endl;
                exit(0);
            }
        }
    }
}
int main() {
    cin >> n >> m;
    vector<pair<int,int>> edges;
    for(int i = 0; i < m; ++i) {
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
        edges.push_back({a,b});
    }

    for(int i = 0; i < n; ++i)
        if(!visited[i]) dfs(i);

    for(const auto& edge : edges) {
        int first = edge.first, second = edge.second;
        if(parent[first] == second) swap(first, second);
        if(parent[second] != first && tin[second] > tin[first])
            swap(first, second);
        printf("%d %d\n", first, second);
    }
}
