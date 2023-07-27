#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using graph = vector<vector<int>>;

ll a,b,n,m;
void solve() {
	cin >> a >> b >> n >> m;
	ll ans = min(a*n, b*n);

	if(n > m) {
		ll discount = n/(m+1)*m;
		ll rem = n%(m+1);
		ans = min(ans, a*discount + min(a,b)*rem);
	}

	cout << ans << '\n';
}

int main() {
	ios::sync_with_stdio(false), cin.tie(nullptr);
	int tc; cin >> tc;
	while(tc--) solve();
}

