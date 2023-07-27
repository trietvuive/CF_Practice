#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using graph = vector<vector<int>>;

void solve() {
	string s; cin >> s;
	string left, right;

	int n = s.size(), l = 0, r = n-1;
	while(l <= r-3) {
		if(s[l] == s[r] || s[l] == s[r-1])
			left += s[l], right += s[l];
		else
			left += s[l+1], right += s[l+1];
		l += 2, r -= 2;
	}

	reverse(right.begin(), right.end());
	if(l <= r) left += s[l];
	left += right;
	cout << left << '\n';
}

signed main() {
	ios::sync_with_stdio(false), cin.tie(nullptr);
	int tc = 1;
	while(tc--) solve();
}

