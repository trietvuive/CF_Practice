#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using graph = vector<vector<int>>;

void solve() {
	int n; cin >> n;
	int odd = n*(n+1)/2, even = (n+3)*n/2;

	if(odd % 2 && even % 2) 
		cout << "Odd\n";
	else if(odd % 2 || even % 2)
		cout << "Either\n";
	else cout << "Even\n";
}

signed main() {
	ios::sync_with_stdio(false), cin.tie(nullptr);
	int tc = 1;
	while(tc--) solve();
}

