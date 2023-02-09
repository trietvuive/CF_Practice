#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using graph = vector<vector<int>>;

constexpr ll MAXN = 2e5 + 5;
constexpr ll JMP = 31;

int up[MAXN][JMP], t[MAXN];

int jump(int x, int d) {
	for(int i = 0; i < JMP; ++i)
		if(d & (1 << i))
			x = up[x][i];
	return x;
}

void solve() {
	int n,q; cin >> n >> q;
	for(int i = 1; i <= n; ++i) {
		cin >> t[i];
		up[i][0] = t[i];
	}

	for(int j = 1; j < JMP; ++j) 
		for(int i = 1; i <= n; ++i)
			up[i][j] = up[up[i][j-1]][j-1];

	while(q--) {
		int x,d; cin >> x >> d;
		cout << jump(x,d) << '\n';
	}
}

int main() {
	ios::sync_with_stdio(false), cin.tie(nullptr);
	int tc = 1;
	while(tc--) solve();
}

