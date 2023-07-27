#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using graph = vector<vector<int>>;
constexpr int MX = 2e5 + 5;
ll marker[MX], extra[MX], prefix[MX], a[MX], b[MX], n;


void update(int l, int r) {
	if(r < l) return;

	marker[l] += 1;
	marker[r+1] -= 1;
}

ll get_range(int l, int r) {
	if(r < l) return 0;
	return prefix[r] - prefix[l - 1];
}

int binary_search(int idx, ll val) {
	int lo = idx-1, hi = n+1;
	while (lo < hi) {
		int mid = (lo + hi + 1) / 2;
		if(get_range(idx, mid) <= val) lo = mid;
		else hi = mid-1;
	}

	return lo;
}

void solve() {
	cin >> n;
	memset(marker, 0, sizeof(marker));
	memset(extra, 0, sizeof(extra));

	prefix[0] = 0;
	for(int i = 1; i <= n; ++i) cin >> a[i];
	for(int i = 1; i <= n; ++i) cin >> b[i], prefix[i] = prefix[i-1] + b[i];

	for(int i = 1; i <= n; ++i) {
		int right = binary_search(i, a[i]);
		update(i, right);
		extra[right+1] += a[i] - get_range(i, right);
	}

	for(int i = 1; i <= n; ++i) {
		marker[i] += marker[i-1];
		ll total = marker[i] * b[i] + extra[i];
		cout << total << ' ';
	}
	cout << '\n';
}

int main() {
	ios::sync_with_stdio(false), cin.tie(nullptr);
	int tc; cin >> tc;
	while(tc--) solve();
}

