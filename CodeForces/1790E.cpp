#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using graph = vector<vector<int>>;

void solve() {
	ll x; cin >> x;
	ll y = x*2;
	if(x % 2 || x+y != (x|y)) {
		cout << -1 << '\n';
	}
	else {
		ll a = x, b = 0;
		for(int i = 0; i < 33; ++i) {
			if((x>>i)&1) continue;

			if(x & (1LL << (i+1))) {
				a |= (1LL << i);
				b |= (1LL << i);
			}
		}
		cout << a << ' ' << b << '\n';
	}
}

int main() {
	ios::sync_with_stdio(false), cin.tie(nullptr);
	int tc; cin >> tc;
	while(tc--) solve();
}

