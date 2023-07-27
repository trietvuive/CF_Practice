#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using graph = vector<vector<int>>;

void solve() {
	string s; cin >> s;
	int a_cnt = 0, n = s.size();
	if(s[0] >= s[1]) {
		cout << s[0] << ' ' << s[1] << ' ' << s.substr(2) << endl;
	}
	else {
		int last_idx = n-1;
		for(int i = 1; i < n; ++i) {
			if(s[i] == 'a') {
				last_idx = i;
				break;
			}
		}

		cout << s[0] << ' ' << s.substr(1, last_idx-1) << ' ' << s.substr(last_idx) << endl;
	}
}

int main() {
	ios::sync_with_stdio(false), cin.tie(nullptr);
	int tc; cin >> tc;
	while(tc--) solve();
}

