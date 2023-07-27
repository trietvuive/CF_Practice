#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using graph = vector<vector<int>>;

void solve() {
	int n; cin >> n;
	vector<int> a(n+1);
	set<int> s;
	for (int i = 1; i <= n; i++) cin >> a[i], s.insert(a[i]);

	int left = 1, right = n;
	while(left < right) {
		int mn = *s.begin(), mx = *s.rbegin();
		if(a[left] == mn || a[left] == mx) {
			s.erase(a[left++]);
		} else if(a[right] == mn || a[right] == mx) {
			s.erase(a[right--]);
		} else {
			cout << left << ' ' << right << '\n';
			return;
		}
	}
	cout << -1 << '\n';
}

int main() {
	ios::sync_with_stdio(false), cin.tie(nullptr);
	int tc; cin >> tc;
	while(tc--) solve();
}

