#include<bits/stdc++.h>
using namespace std;

void solve() {
	int n,e; cin >> n;
	int needed_cnt = n;
	for(int i = 0; i < n; i++) {
		cin >> e;
		while(e % 2 == 0) {
			e /= 2;
			--needed_cnt;
		}
	}

	int ans = 0;
	int pow_2 = 1, cnt_2 = 0;
	while(pow_2 <= n) {
		pow_2 *= 2;
		++cnt_2;
	}

	while(needed_cnt > 0 && cnt_2 > 0) {
		for(int i = 1; pow_2 * i <= n && needed_cnt > 0; i += 2) {
			needed_cnt -= cnt_2;
			++ans;
		}

		pow_2 /= 2, --cnt_2;
	}

	if(needed_cnt > 0) {
		cout << -1 << '\n';
	} else {
		cout << ans << '\n';
	}
}

int main() {
	ios::sync_with_stdio(false), cin.tie(nullptr);
	int tc; cin >> tc;
	while(tc--) {
		solve();
	}
}
