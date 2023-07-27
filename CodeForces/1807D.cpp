#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using graph = vector<vector<int>>;
const int maxN = 2e5 + 5;

int N, Q;
ll a[maxN], prefix[maxN];

void solve() {
	cin >> N >> Q;
	ll sm = 0;
	for(int i = 1; i <= N; ++i) cin >> a[i], a[i] %= 2, prefix[i] = prefix[i-1] + a[i], sm += a[i];

	for(int i = 1; i <= Q; ++i) {
		int l,r,k; cin >> l >> r >> k;
		k %= 2;
		int cnt = prefix[r] - prefix[l-1];
		int new_sm = sm - cnt + k*(r-l+1);
		if(new_sm % 2) cout << "YES\n";
		else cout << "NO\n";
	}
}

signed main() {
	ios::sync_with_stdio(false), cin.tie(nullptr);
	int tc; cin >> tc;
	while(tc--) solve();
}

