#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using graph = vector<vector<int>>;
constexpr ll MOD = 1e9 + 7;

void solve() {
	ll n, skip, total = 0; cin >> n;
	vector<ll> worlds(n+1), permutation(n);

	for(int i = 1; i <= n; ++i) cin >> worlds[i], total += worlds[i];
	for(int i = 0; i < n; ++i) cin >> skip;
	for(int i = 0; i < n; ++i) cin >> permutation[i];

	if(worlds[permutation[0]] * 2 >= total) {
		if(n == 2 && worlds[permutation[0]] * 2 == total) {
			cout << 0.25 << endl;
		} else {
			cout << 0.5 << endl;
		}
		cout << permutation[0] << ' ';
		for(int i = 2; i < n; ++i) cout << permutation[i] << ' ';
		if(n > 1) cout << permutation[1] << endl;

	} else {
		cout << 1 << endl;
		for(int i = 1; i < n; ++i) cout << permutation[i] << ' ';
		cout << permutation[0] << endl;
	}
}

signed main() {
	ios::sync_with_stdio(false), cin.tie(nullptr);
	int tc = 1;
	while(tc--) solve();
}

