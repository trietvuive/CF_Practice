#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using graph = vector<vector<int>>;

void solve() {
	int n; cin >> n;
	if(n % 2 == 0) {
		cout << "NO\n";
		return;
	}
	
	cout << "YES\n";
	int m = (n-1)/2;
	for(int i = 1; i <= m; ++i) {
		cout << 3*m+i+2-n << ' ' << (n+1-i) << '\n';
	}
	for(int i = m+1; i <= 2*m+1; ++i) {
		cout << m+i+1-n << ' ' << (n+1-i) << '\n';
	}
}

int main() {
	ios::sync_with_stdio(false), cin.tie(nullptr);
	int tc; cin >> tc;
	while(tc--) solve();
}

