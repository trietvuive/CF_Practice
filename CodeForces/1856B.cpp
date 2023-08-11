#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using graph = vector<vector<int>>;
constexpr ll MOD = 1e9 + 7;

void solve() {
	int n; cin >> n;
	ll delta = 0, element;
	for(int i = 0; i < n; ++i) 
		cin >> element, delta += element == 1 ? - 1 : element - 1; 
	
	if(n > 1 && delta >= 0)
		cout << "YES\n";
	else cout << "NO\n";
}

signed main() {
	ios::sync_with_stdio(false), cin.tie(nullptr);
	int tc; cin >> tc;
	while(tc--) solve();
}

