#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using graph = vector<vector<int>>;

void solve() {
	ll n, x, m;
	cin >> n >> x;
	if(n == x) {
		cout << n << '\n';
		return;
	}

	m = n;
	for(ll i = 0; i < 63; ++i) {
		m |= (1LL << i);
		if((n & m) == x && m > n) {
			cout << m << '\n';
			return;
		}
		m -= (1LL << i);
	}
	cout << -1 << '\n';
}

int main() {
	ios::sync_with_stdio(false), cin.tie(nullptr);
	int tc; cin >> tc;
	while(tc--) solve();
}

