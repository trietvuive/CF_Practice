#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using graph = vector<vector<int>>;

void solve() {
	int n; cin >> n;
	int y = 0, x = 0;
	bool passed = false;
	for(int i = 0; i < n; ++i) {
		char direction; cin >> direction;
		if(direction == 'U') y++;
		else if(direction == 'D') y--;
		else if(direction == 'L') x--;
		else if(direction == 'R') x++;

		if(x == 1 && y == 1) passed = true;
	}

	if(passed) cout << "YES\n";
	else cout << "NO\n";
}

int main() {
	ios::sync_with_stdio(false), cin.tie(nullptr);
	int tc; cin >> tc;
	while(tc--) solve();
}

