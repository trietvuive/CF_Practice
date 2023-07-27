#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using graph = vector<vector<int>>;

void solve() {
	int n; cin >> n;
	vector<int> a(n+1), b(n+1);
	for(int i = 1; i <= n; ++i) cin >> a[i];
	for(int i = 1; i <= n; ++i) cin >> b[i];

	int start = 1;
	while(a[start] == b[start]) ++start;
	
	int end = start;
	while(end+1 <= n && b[end+1] >= b[end]) ++end;

	while(start-1 >= 1 && b[start-1] <= b[start]) --start;

	cout << start << ' ' << end << '\n';
}

signed main() {
	ios::sync_with_stdio(false), cin.tie(nullptr);
	int tc; cin >> tc;
	while(tc--) solve();
}

