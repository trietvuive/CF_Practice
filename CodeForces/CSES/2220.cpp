#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using graph = vector<vector<int>>;


ll count_brute_force(ll right) {
	ll ans = 0, bound = 100;
	map<char, vector<int>> last_digit;
	for(ll i = 0; i <= right; ++i) {
		bool valid = true;
		string repr = to_string(i);
		for(int j = 1; j < repr.size(); ++j)
			if(repr[j] == repr[j-1]) 
				valid = false;
		if(valid) {
			ans++;
			last_digit[repr.back()].push_back(i);
		}
	}

	return ans;
}

ll count(ll right) {
	string repr = to_string(right);
	bool repeated = false;

	ll dp[repr.size()][10];
	memset(dp, 0, sizeof(dp));

	for(int i = 0; i < repr[0]-'0'; i++) 
		dp[0][i] = 1;

	for(int i = 1; i < repr.size(); ++i) {
		ll sm_prev_row = accumulate(dp[i-1], dp[i-1]+10, 0LL);
		for(int digit = 0; digit < 10; ++digit) 
			dp[i][digit] = sm_prev_row - dp[i-1][digit];

		++dp[i][0];

		if(!repeated)
			for(int digit = 0; digit < repr[i]-'0'; ++digit)
				if(digit != repr[i-1]-'0')
					dp[i][digit]++;

		repeated |= repr[i] == repr[i-1];

	}
	ll ans = accumulate(dp[repr.size()-1], dp[repr.size()-1]+10, 0LL);
	if(!repeated) ++ans;

	return ans;
}

void solve() {
	ll a, b; cin >> a >> b;
	if(a == 0) cout << count(b) << endl;
	else cout << count(b) - count(a-1) << endl;
}

int main() {
	ios::sync_with_stdio(false), cin.tie(nullptr);
	int tc = 1;
	while(tc--) solve();
}

