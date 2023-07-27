#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using graph = vector<vector<int>>;

int h[105];
void solve() {
	int n, one_count = 0, skip = 0;
	cin >> n;
	for(int i = 0; i < n; ++i) {
		cin >> h[i];
		if(h[i] == 1) one_count++;
	}
	cout << n - one_count / 2 << '\n';
}

int main() {
	ios::sync_with_stdio(false), cin.tie(nullptr);
	int tc; cin >> tc;
	while(tc--) solve();
}

