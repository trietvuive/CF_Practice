#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using graph = vector<vector<int>>;

int n,a[55];

void solve() {
	int n; cin >> n;
	int x = 1, y = n*n;
	for(int i = 1; i <= n; ++i) {
		for(int j = 1; j <= n; ++j) {
			if(((i-1) * n + j) % 2) a[j] = x++;
			else a[j] = y--;
		}

		if(i % 2) {
			for(int j = 1; j <= n; ++j) cout << a[j] << " ";
		} else {
			for(int j = n; j >= 1; --j) cout << a[j] << " ";
		}
		cout << '\n';
	}
}

int main() {
	ios::sync_with_stdio(false), cin.tie(nullptr);
	int tc; cin >> tc;
	while(tc--) solve();
}

