#include<bits/stdc++.h>
using namespace std;
const int INF = 1e9;

void solve() {
    int n, h, l; cin >> n >> h >> l;
    queue<int> q;
    set<int> s;
    vector<vector<int>> g(n);
    vector<int> ans(n, INF);

    for (int i = 0; i < h; i++) {
        int x; cin >> x;
        ans[x] = 0;
        q.push(x);
        s.insert(x);
    }

    for(int i = 0; i < l; i++) {
        int a, b; cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    while(!q.empty()) {
        int sz = q.size();
        for(int i = 0; i < sz; ++i) {
            int u = q.front(); q.pop();
            for(int v : g[u]) {
                if(s.count(v)) continue;
                ans[v] = min(ans[v], ans[u] + 1);
                q.push(v);
                s.insert(v);
            }
        }
    }

    int mx_score = 0, mx_idx = -1;
    for(int i = 0; i < n; ++i) {
        if(ans[i] > mx_score) {
            mx_score = ans[i];
            mx_idx = i;
        }
    }

    cout << mx_idx << '\n';
}
int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    solve();
}
