#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using graph = vector<vector<int>>;

void solve() {
	ll n,k; cin >> n >> k;
	vector<vector<int>> matrix(n, vector<int>(n, 0));

	for(int i = 0; i < n; ++i)
		for(int j = 0; j < n; ++j)
			cin >> matrix[i][j];

	for(int i = 0; i < n; ++i) {
		for(int j = 0; j < n; ++j) {
			if(matrix[i][j] != matrix[n-1-i][n-1-j]) {
				--k, matrix[i][j] ^= 1;
			}
		}
	}

	if(k >= 0 && (k % 2 == 0 || n % 2 == 1)) 
		cout << "YES\n";
	else
		cout << "NO\n";
}

signed main() {
	ios::sync_with_stdio(false), cin.tie(nullptr);
	int tc; cin >> tc;
	while(tc--) solve();
}

