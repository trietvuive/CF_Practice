#include<bits/stdc++.h>
using namespace std;

void solve() {
	int n; char c; cin >> n >> c;
	string s; cin >> s;

	int max_r = 0, max_y = 0, first_g = -1, last_g = -1;
	for(int i = 0; i < n; ++i) {
		if(s[i] == 'g') {
			first_g = i;
			break;
		}
	}

	for(int i = n-1; i >= 0; --i) {
		if(s[i] == 'g') last_g = i;
		if(s[i] == 'y') {
			if(last_g != -1) max_y = max(max_y, last_g - i);
			else max_y = max(max_y, n + first_g - i);
		}
		if(s[i] == 'r') {
			if(last_g != -1) max_r = max(max_r, last_g - i);
			else max_r = max(max_r, n + first_g - i);
		}
	}

	if(c == 'g') cout << 0 << '\n';
	if(c == 'y') cout << max_y << '\n';
	if(c == 'r') cout << max_r << '\n';
}

int main() {
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	int tc; cin >> tc;
	while(tc--) {
		solve();
	}
}
