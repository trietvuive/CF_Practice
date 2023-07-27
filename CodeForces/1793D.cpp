#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using graph = vector<vector<int>>;

ll n, p[200005], q[200005], ans;

ll sm(ll n) {
	return n * (n + 1) / 2;
}

void solve() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		ll x; cin >> x;
		p[x] = i;
	}

	for (int i = 0; i < n; i++) {
		ll x; cin >> x;
		q[x] = i;
	}

	ll left_bound = n+1, right_bound = -1;
	ll left_loc = min(p[1], q[1]), right_loc = max(p[1], q[1]);
	ans = sm(left_loc) + sm(right_loc - left_loc - 1) + sm(n - right_loc - 1) + 1;

	for(int i = 2; i <= n; ++i) {

		left_bound = min(left_bound, left_loc);
		right_bound = max(right_bound, right_loc);


		left_loc = min(p[i], q[i]);
		right_loc = max(p[i], q[i]);


		if(right_bound < left_loc) 
			ans += (left_loc - right_bound) * (left_bound + 1);
		if(left_loc < left_bound && right_bound < right_loc) 
			ans += (right_loc - right_bound) * (left_bound - left_loc);
		if(right_loc < left_bound) 
			ans += (n - right_bound) * (left_bound - right_loc);
	}
	cout << ans << '\n';
}

int main() {
	ios::sync_with_stdio(false), cin.tie(nullptr);
	int tc = 1;
	while(tc--) solve();
}

