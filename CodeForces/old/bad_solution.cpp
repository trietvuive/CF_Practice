#include<bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false), cin.tie(NULL);
	int tc; cin >> tc;
	while(tc--) {
		int n,e, prev = -1, first, last; cin >> n;
		int mn = 1e9, mx = -1e9, ans = 0;
		for(int i = 1; i <= n; ++i) {
			cin >> e;
			if(prev != -1) ans = max(ans, prev - e);
			prev = e;
			if(i == 1) first = e;
			else if(i == n) last = e;

			mx = max(mx, e), mn = min(mn, e);
		}
		cout << max({ans, mx - first, last - mn}) << '\n';
	}
}
