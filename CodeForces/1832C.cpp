#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using graph = vector<vector<int>>;
constexpr ll MOD = 1e9 + 7;

void solve() {
	int n, element; cin >> n;
	vector<int> a;
	for(int i = 0; i < n; ++i) {
		cin >> element;
		if(a.size() == 0 || element != a.back()) 
			a.push_back(element);
	}

	n = a.size();
	int ans = 1 + (n > 1);
	for(int i = 1; i < n-1; ++i) 
		if((a[i-1] < a[i] && a[i] > a[i+1]) ||
			(a[i-1] > a[i] && a[i] < a[i+1]))
			++ans;

	cout << ans << '\n';
}

signed main() {
	ios::sync_with_stdio(false), cin.tie(nullptr);
	int tc; cin >> tc;
	while(tc--) solve();
}

