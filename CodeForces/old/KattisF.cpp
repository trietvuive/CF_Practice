#include<bits/stdc++.h>
using namespace std;

int n, m;
map<int, int> multisource(const vector<string> &a) {
    queue<int> q;
    map<int, int> dist;
    for(int i = 0; i < a.size(); ++i) {
        for(int j = 0; j < a[0].size(); ++j) {
            if(a[i][j] == '1') {
                q.push(i * a[0].size() + j);
                dist[i * a[0].size() + j] = 0;
            }
        }
    }
    while(!q.empty()) {
        int u = q.front();
        q.pop();
        int x = u / a[0].size();
        int y = u % a[0].size();
        for(int i = -1; i <= 1; ++i) {
            for(int j = -1; j <= 1; ++j) {
                if(abs(i) + abs(j) == 1) {
                    int nx = x + i;
                    int ny = y + j;
                    if(nx >= 0 && nx < a.size() && ny >= 0 && ny < a[0].size() && a[nx][ny] == '.') {
                        int v = nx * a[0].size() + ny;
                        if(dist.find(v) == dist.end()) {
                            dist[v] = dist[u] + 1;
                            q.push(v);
                        }
                    }
                }
            }
        }
    }
    return dist;
}

void solve() {
    cin >> n >> m;
    vector<string> a;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        a.push_back(s);
    }
    
}

int main() {
    int tc; cin >> tc;
    while(tc--)
        solve();
}
