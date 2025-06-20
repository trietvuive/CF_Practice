#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using graph = vector<vector<int>>;

int gcd(int a, int b) {
    if(b == 0) return a;
    return gcd(b, a % b);
}

void solve() {
	int n; cin >> n;
    vector<int> a(n);
    int g = -1;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        if(g == -1) g = a[i];
        else g = gcd(g, a[i]);
    }

    set<int> visited;
    queue<int> pq;
    for(int i = 0; i < n; i++) {
        pq.push(a[i]);
    }

    int iteration = 0;

    while(!pq.empty()) {
        int sz = pq.size();
        bool found = false;
        for(int i = 0; i < sz; i++) {
            int x = pq.front(); pq.pop();
            if(x == g) {
                found = true;
                break;
            }
            if(visited.count(x)) continue;
            visited.insert(x);

            for(int i : a) pq.push(gcd(x, i));
        }
        if(found) break;
        iteration++;
    }

    if(iteration == 0) {
        int cnt = 0;
        for(int i : a) if(i != g) cnt++;
        cout << cnt << endl;
    } else {
        cout << iteration + n - 1 << endl;
    }
}

int main() {
	ios::sync_with_stdio(false), cin.tie(nullptr);
	int tc = 1; cin >> tc;
	while(tc--) solve();
}

