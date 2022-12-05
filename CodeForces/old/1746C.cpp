#include<bits/stdc++.h>
using namespace std;

int p[100005];
void solve() {
	int n; cin >> n;
	for(int i = 1; i <= n; ++i) {
		int e; cin >> e;
		p[e] = i;
	}

	for(int i = 1; i <= n; ++i) {
		cout << min(n, p[i] + 1) << " \n"[i == n];
	}
}

int main() {
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	int tc; cin >> tc;
	while(tc--) solve();
}
