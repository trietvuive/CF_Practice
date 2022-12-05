#include<bits/stdc++.h>
using namespace std;
using ll = long long;

ll n, ar[200005], prefix[200005];
void solve() {
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> ar[i], prefix[i] = prefix[i - 1] + ar[i];

	map<ll, ll> mp;
	ll ans = 0;
	for(int i = n; i >= 1; --i) {
		mp[prefix[i]]++;
		if(ar[i] == 0) {
			ll mx = 0;
			for(auto& it : mp) mx = max(mx, it.second);

			ans += mx;
			mp.clear();
		}
	}
	ans += mp[0];
	cout << ans << '\n';
}

int main() {
	ios::sync_with_stdio(false), cin.tie(nullptr);
	int tc; cin >> tc;
	while(tc--) {
		solve();
	}
}
