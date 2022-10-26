#include<bits/stdc++.h>
using namespace std;


int ar[1000000], prefix[1000000];
void solve() {
	int n; cin >> n;
	prefix[0] = 0;
	for(int i = 1; i <= n; ++i) {
		cin >> ar[i];
		prefix[i] = prefix[i - 1] + ar[i];
	}

	int ans = n, zero = 0;
	for(int i = n; i >= 1; --i) {
		zero += ar[i] == 0;
		ans = min(ans, max(zero, prefix[i-1]));
	}
	if(prefix[n] == 0) cout << 0 << '\n';
	else cout << ans << '\n';
}

int main() {
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	int tc; cin >> tc;
	while(tc--) solve();
}
