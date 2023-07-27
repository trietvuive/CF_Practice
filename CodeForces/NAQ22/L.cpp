#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using graph = vector<vector<int>>;

ll gcd(ll a, ll b) {
	if (b == 0) return a;
	return gcd(b, a % b);
}

bool is_reachable(ll y, ll x, ll cost) {
	while(y >= 2 && x >= 2)
		y -= 2, x -= 2, cost -= 3;
	return x + y <= cost;
}

void brute_force(ll t) {
	for(ll x = t; x > 0; --x) {
		for(ll y = t; y >= 0; --y) {
			if(is_reachable(y, x, t)) {
				printf("Height of row %lld is %lld\n", x, y);
				break;
			}
		}
	}
}

void solve() {
	ll t, s; cin >> t >> s;

	ll total = 0, diff = 0;
	for(ll i = s; i >= 1; --i) {
		ll diag_step = min(s/3, min(i/2, s-i));
		ll spider_height = s - i + diag_step;
		ll cab_height = max(0ll, t - i);

		diff += max(0ll, spider_height - cab_height) * 2  * 2;
		if(t < i) diff += 2;

		total += (2 * spider_height + 1) * 2;
	}

	total += 2 * s + 1, diff += 2 * max(0ll, s - t);

	ll g = gcd(total, diff);
	diff /= g, total /= g;
	
	if(diff == 0) cout << 1 << endl;
	else cout << total-diff << "/" << total << endl;
}

int main() {
	ios::sync_with_stdio(false), cin.tie(nullptr);
	int tc = 1;
	while(tc--) solve();
}

