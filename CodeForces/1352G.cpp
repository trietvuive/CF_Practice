#include<bits/stdc++.h>
#define endl '\n'
using namespace std;

using ll = long long;
using graph = vector<vector<int>>;
constexpr ll MOD = 1e9 + 7;

void solve() {
	int n; cin >> n;
	if(n < 4) {
		cout << -1 << endl;
		return;
	}

	for(int i = n-n%2; i > 4; i -= 2)
		cout << i << ' ';
	cout << "2 4 ";
	for(int i = 1; i <= n; i += 2)
		cout << i << ' ';
	cout << endl;
}

signed main() {
	ios::sync_with_stdio(false), cin.tie(nullptr);
	int tc; cin >> tc;
	while(tc--) solve();
}

