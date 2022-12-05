#include<bits/stdc++.h>
using namespace std;
using ll = long long;
ll a,b,c,d;

void solve() {
	cin >> a >> b >> c >> d;
	ll mul = a * b;
	vector<ll> da, db;

	for(int i = 1; i * i <= a; ++i) {
		if(a % i == 0) {
			da.push_back(i);
			if(i * i != a) da.push_back(a / i);
		}
	}

	for(int i = 1; i * i <= b; ++i) {
		if(b % i == 0) {
			db.push_back(i);
			if(i * i != b) db.push_back(b / i);
		}
	}

	for(ll div_a : da) {
		for(ll div_b : db) {
			ll div = div_a * div_b;
			ll sy = a*b / div;
			ll y = d/sy * sy, x = c/div * div;

			if(x > a && y > b) {
				cout << x << " " << y << '\n';
				return;
			}
		}
	}

	cout << -1 << ' ' << -1 << '\n';
}

int main() {
	ios::sync_with_stdio(false), cin.tie(nullptr);
	int t;
	cin >> t;
	while(t--) {
		solve();
	}
}
