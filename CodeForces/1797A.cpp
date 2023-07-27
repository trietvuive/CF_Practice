#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using graph = vector<vector<int>>;

ll lock(ll r, ll c, ll n, ll m) {
	ll ans = 4;
	if(r == n || r == 1) --ans;
	if(c == m || c == 1) --ans;
	return ans;
}

void solve() {
	ll n,m,x1,x2,y1,y2;
	cin >> n >> m >> x1 >> y1 >> x2 >> y2;
	ll ans = 4;
	
	if(abs(x1-x2) >= 2) ans = min(ans, m);
	if(abs(y1-y2) >= 2) ans = min(ans, n);
	ans = min(ans, lock(x1,y1,n,m));
	ans = min(ans, lock(x2,y2,n,m));

	cout << ans << '\n';
}

signed main() {
	ios::sync_with_stdio(false), cin.tie(nullptr);
	int tc; cin >> tc;
	while(tc--) solve();
}

