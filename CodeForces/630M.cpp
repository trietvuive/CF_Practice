#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using graph = vector<vector<int>>;

void solve() {
	ll n; cin >> n;
	n = (n % 360 + 360) % 360;
	n = (n + 44) % 360;
	ll ans = (n % 359) / 90;
	cout << ans << '\n';
}

int main() {
	ios::sync_with_stdio(false), cin.tie(nullptr);
	int tc = 1;
	while(tc--) solve();
}

