#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using graph = vector<vector<int>>;

void solve() {
	int n, d; cin >> n >> d;
	string s; cin >> s;
	int idx = s.size();
	for(int i = 0; i < s.size(); ++i) {
		if(s[i] - '0' < d) {
			idx = i; 
			break;
		}
	}
	string ans = s.substr(0,idx) + to_string(d) + s.substr(idx);
	cout << ans << '\n';
}

signed main() {
	ios::sync_with_stdio(false), cin.tie(nullptr);
	int tc; cin >> tc;
	while(tc--) solve();
}

