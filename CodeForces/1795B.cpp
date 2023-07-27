#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using graph = vector<vector<int>>;

void solve() {
	int n, k; cin >> n >> k;
	set<int> begin, end;
	for (int i = 0; i < n; i++) {
		int x, y;
		cin >> x >> y;
		begin.insert(x);
		end.insert(y);
	}

	if(begin.count(k) && end.count(k)) {
		cout << "YES\n";
	} else {
		cout << "NO\n";
	}
}

int main() {
	ios::sync_with_stdio(false), cin.tie(nullptr);
	int tc; cin >> tc;
	while(tc--) solve();
}

