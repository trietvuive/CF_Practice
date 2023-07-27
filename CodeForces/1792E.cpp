#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using graph = vector<vector<int>>;

ll n,m1,m2;

void solve() {
	cin >> n >> m1 >> m2;
	set<ll> q, q1, q2;
	q1.insert(1);
	return;
	for(ll i = 1; i * i <= m1; ++i) {
		if(m1 % i == 0) {
			q1.insert(i);
			q1.insert(m1 / i);
		}
	}

	for(ll i = 1; i * i <= m2; ++i) {
		if(m2 % i == 0) {
			q2.insert(i);
			q2.insert(m2 / i);
		}
	}

	for(ll i : q1)
		for(ll j : q2)
			q.insert(i * j);

	ll x = 0, y = 0;
	for(ll div : q) {
		for(auto row = q.lower_bound((div+n-1)/n); row != q.end(); ++row) {
			if(*row > n) break;
			if(div % *row == 0) {
				++x, y ^= *row;
				break;
			}
		}
	}
	cout << x << ' ' << y << '\n';

}

int main() {
	ios::sync_with_stdio(false), cin.tie(nullptr);
	int tc; cin >> tc;
	while(tc--) solve();
}

