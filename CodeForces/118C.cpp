#include<bits/stdc++.h>
using namespace std;
int cnt[10];

pair<int, string> min_sum(int idx, int k, string s) {
	int left = idx-1, right = idx+1, dist = 1, n = s.size();
	k -= cnt[idx];
	int ans = 0;
	while(k > 0) {
		if(right <= 9) {
			for(int i = 0; i < n && k > 0; ++i) {
				if(s[i] - '0' == right) {
					s[i] = idx + '0';
					--k;
					ans += dist;
				}
			}
			++right;
		}

		if(left >= 0) {
			for(int i = n-1; i >= 0 && k > 0; --i) {
				if(s[i] - '0' == left) {
					s[i] = idx + '0';
					--k;
					ans += dist;
				}
			}
			--left;
		}

		++dist;
	}

	return {ans, s};
}

void solve() {
	int n, k;
	cin >> n >> k;
	string s(n, '0');
	for(int i = 0; i < n; ++i) 
		cin >> s[i], cnt[s[i] - '0']++;

	int ans = INT_MAX;
	string res;
	for(int i = 0; i <= 9; ++i) {
		auto [cnt, best] = min_sum(i, k, s);
		if(cnt < ans || (cnt == ans && best < res)) {
			ans = cnt;
			res = best;
		}
	}
	
	cout << ans << endl << res << endl;
}

int main() {
//	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	solve();
}
