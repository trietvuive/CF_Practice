#include<bits/stdc++.h>
using namespace std;

void solve() {
	string s;
	int n; cin >> n >> s;

	int cnt = 0;
	bool first = false;
	for(int i = 0; i < n-1; ++i) {
		if((s[i] == '0' && s[i+1] == '1') || (s[i] == '1' && s[i+1] == '0')) {
			if(cnt == 0 && s[i] == '0' && s[i+1] == '1') {
				first = true;
			}
			++cnt;
		}
	}
	cout << cnt - first << '\n';
}

int main() {
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	int tc; cin >> tc;
	while(tc--) {
		solve();
	}
}
