#include<bits/stdc++.h>
#define ll long long
using namespace std;

void solve() {
	int n; cin >> n;
	ll ans = 0;
	ans += 5 * (n/3);
	ans += 3 * (n/2 - n/3);
	ans += n - n/2;
	cout << ans << '\n';
}
int main() {
	ios_base::sync_with_stdio(false), cin.tie(NULL);
	int tc; cin >> tc;
	while(tc--) solve();
}
