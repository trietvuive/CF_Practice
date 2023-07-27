#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using graph = vector<vector<int>>;

void solve() {
	int n, k, m; cin >> n >> k >> m;
	vector<int> a(n+1);
	for (int i = 1; i <= m; i++) cin >> a[i];

	if((n-m) % (k-1) != 0) {
		cout << "NO\n";
		return;
	}

	for(int i = 1; i <= m; ++i) {
		int left = a[i] - i, right = (n-a[i]) - (m-i);
		if(left >= k/2 && right >= k/2) {
			cout << "YES\n";
			return;
		}
	}
	cout << "NO\n";
}

int main() {
	ios::sync_with_stdio(false), cin.tie(nullptr);
	int tc; cin >> tc;
	while(tc--) solve();
}

