#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using graph = vector<vector<int>>;

void solve() {
	int n,k; cin >> n >> k;
	k = (n+1)*n/2 - k;
	vector<int> a(n+1);
	for(int i = 0; i < n; ++i) a[i] = 2;

	int idx = n-1;
	while(k) {
		if(a[idx] == 2) a[idx] = -1;
		else a[idx] -= 2;

		if(-a[idx] > 2 * idx) --idx;
		--k;
	}

	for(int i = 0; i < n; ++i) cout << a[i] << " \n"[i==n-1];
}

signed main() {
	ios::sync_with_stdio(false), cin.tie(nullptr);
	int tc; cin >> tc;
	while(tc--) solve();
}

