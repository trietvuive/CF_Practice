#include<bits/stdc++.h>
using pii = std::pair<int, int>;
using namespace std;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<pii>> g(n+1);

    for(int i = 0; i < m; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        g[u].push_back({v, w});
        g[v].push_back({u, w});
    }

    set<int> s;
    int cost = 0;
    deque<int> q;
    q.push_back(1);

    while(!q.empty()) {
        int sz = q.size();
        for(int i = 0; i < sz; ++i) {
            int u = q.front();
            q.pop_front();
            if(u == n) {
                cout << cost << endl;
                return;
            }

            if(s.count(u)) continue;
            s.insert(u);
            for(auto& [v, w] : g[u]) {
                if(w == 0) ++sz, q.push_front(v);
                q.push_back(v);
            }
        }
        ++cost;
    }
}
int main() {
    solve();
}
