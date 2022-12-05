#include<bits/stdc++.h>

using namespace std;

int x[100005];
void solve() {
	int n; cin >> n;
	for(int i = 0; i < n; ++i) cin >> x[i];

	double max_left = -1e9, max_right = -1e9;
	for(int i = 0; i < n; ++i) {
		int t; cin >> t;
		max_left = max(max_left, (double)t - x[i]);
		max_right = max(max_right, (double)t + x[i]);
	}
	double time = (max_left + max_right) / 2;
	// cout << time - max_left << '\n';
	cout << fixed << setprecision(9) << time - max_left << '\n';
}
int main() {
	ios::sync_with_stdio(false), cin.tie(nullptr);
	int tc; cin >> tc;
	while(tc--) solve();
}
