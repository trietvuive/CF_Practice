#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using graph = vector<vector<int>>;
const ll MOD = 998244353;
ll a[105][105], dp[105][105], n;

bool check(int right, int last) {
	for(int i = 0; i < right; ++i) {
		if(a[i][right-1] == 0) continue;
		if(a[i][right-1] == 1 && last > i) return false;
		if(a[i][right-1] == 2 && last <= i) return false;
	}
	return true;
}

void solve() {
	cin >> n;
	for(int i = 0; i < n; ++i)
		for(int j = i; j < n; ++j)
			cin >> a[i][j];

	if(a[0][0] != 2) dp[1][0] = 2;
	for(int i = 1; i < n; ++i) 
		for(int j = 0; j < i; ++j) 
			for(int k : {i,j}) 
				if(check(i+1, k))
					dp[i+1][k] = (dp[i+1][k] + dp[i][j]) % MOD;

	ll ans = 0;
	for(int i = 0; i < n; ++i) ans = (ans + dp[n][i]) % MOD;
	cout << ans << endl;
}

int main() {
	ios::sync_with_stdio(false), cin.tie(nullptr);
	int tc = 1;
	while(tc--) solve();
}

