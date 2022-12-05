#include<bits/stdc++.h>
using ll = long long;
using namespace std;

ll board[55][55], dp[55][55], INF = 1e9, n, k;

vector<int> set_board(int k, vector<int> &coords) {
	vector<int> ret;
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
			if(board[i][j] == k) {
				for(int coord : coords) {
					int row = coord / n, col = coord % n;
					dp[i][j] = min(dp[i][j], abs(row - i) + abs(col - j) + dp[row][col]);
				}
				ret.push_back(i * n + j);
			}
		}
	}
	return ret;
}
void solve() {
	cin >> n >> k;
	vector<int> coords;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> board[i][j];
			dp[i][j] = (board[i][j] == 1) ? 0 : INF;
			if(board[i][j] == 1) coords.push_back(i * n + j);
		}
	}

	ll ans = INF;
	for(int i = 2; i <= k; ++i) {
		coords = set_board(i, coords);
	}

	for(int coord : coords) {
		int row = coord / n, col = coord % n;
		ans = min(ans, dp[row][col]);
	}

	if(ans == INF) cout << -1 << endl;
	else cout << ans << '\n';
}

int main() {
	ios::sync_with_stdio(false), cin.tie(nullptr);
	solve();
}
