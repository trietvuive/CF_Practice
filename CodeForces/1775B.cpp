#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using graph = vector<vector<int>>;

vector<int> c[100005];

void solve() {
	int n; cin >> n;
	map<int, int> mp;
	bool output = false;
	for(int i = 0; i < n; ++i) {
		int k; cin >> k;
		for(int j = 0; j < k; ++j) {
			int x; cin >> x;
			c[i].push_back(x);
			mp[x]++;
		}
	}

	for(int i = 0; i < n; ++i) {
		bool diff = false;
		for(int j : c[i]) {
			if(mp[j] == 1) {
				diff = true;
				break;
			}
		}
		c[i].clear();
		if(!diff) output = true;
	}

	if(output) cout << "YES\n";
	else cout << "NO\n";
}

int main() {
	ios::sync_with_stdio(false), cin.tie(nullptr);
	int tc; cin >> tc;
	while(tc--) solve();
}
