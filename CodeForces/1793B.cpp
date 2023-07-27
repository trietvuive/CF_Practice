#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using graph = vector<vector<int>>;

void solve() {
	int a, b; cin >> a >> b;
	cout << 2*(a-b) << '\n';
	for(int i = a; i >= b; --i) cout << i << ' ';
	for(int i = b+1; i < a; ++i) cout << i << ' ';
	cout << '\n';
}

int main() {
	ios::sync_with_stdio(false), cin.tie(nullptr);
	int tc; cin >> tc;
	while(tc--) solve();
}

