#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using graph = vector<vector<int>>;
constexpr ll MOD = 1e9 + 7;

double dp[301][301][301], n;

double recurse(int one, int two, int three) {
	if(one == 0 && two == 0 && three == 0) return 0;
	if(dp[one][two][three] != -1) return dp[one][two][three];

	double remaining = one + two + three;
	double ans = n/remaining; 
	if(one > 0) ans += one/remaining * recurse(one-1, two, three);
	if(two > 0) ans += two/remaining * recurse(one+1, two-1, three); 
	if(three > 0) ans += three/remaining * recurse(one, two+1, three-1);

	return dp[one][two][three] = ans;
}

void solve() {
	cin >> n;
	int one = 0, two = 0, three = 0, a;
	for(int i = 0; i <= 300; ++i)
		for(int j = 0; j <= 300; ++j)
			for(int h = 0; h <= 300; ++h)
				dp[i][j][h] = -1;

	for(int i = 0; i < n; ++i) {
		cin >> a;
		if(a == 1) ++one;
		if(a == 2) ++two;
		if(a == 3) ++three;
	}

	cout << fixed << setprecision(10) << recurse(one, two, three) << '\n';
}

signed main() {
	ios::sync_with_stdio(false), cin.tie(nullptr);
	int tc = 1;
	while(tc--) solve();
}

