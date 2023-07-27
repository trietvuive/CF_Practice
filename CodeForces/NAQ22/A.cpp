#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define int long long
using graph = vector<vector<int>>;

void solve() {
	int n; cin >> n;

	vector<int> a(n+1), prefix(n+1);
	for (int i = 1; i <= n; i++) cin >> a[i];
	sort(a.begin()+1, a.end(), greater<int>());

	for (int i = 1; i <= n; i++) prefix[i] = prefix[i-1] + a[i];


	function<int(int, int)> query = [&] (int l, int r) {
		return prefix[r] - prefix[l-1];
	};

	function<int(int)> cutoff = [&] (int index) {
		int stronger = query(1, index - 1);
		return lower_bound(prefix.begin(), prefix.end(), 2 * stronger) - prefix.begin();
	};

	vector<int> attack_prefix(n+2, 0);
	for(int i = 1; i <= n; ++i) {

		if(i > 1) {
			int cutoff_idx = cutoff(i);
			attack_prefix[0] -= a[i];
			attack_prefix[cutoff_idx + 1] += 2*a[i];

		} else {
			attack_prefix[2] += a[i];
		}
	}

	partial_sum(attack_prefix.begin(), attack_prefix.end(), attack_prefix.begin());
	for(int i = n; i >= 1; --i) {
		if(attack_prefix[i] <= 0) {
			cout << i << endl;
			return;
		}
	}
	cout << 1 << endl;
}

int32_t main() {
	ios::sync_with_stdio(false), cin.tie(nullptr);
	int tc = 1;
	while(tc--) solve();
}

