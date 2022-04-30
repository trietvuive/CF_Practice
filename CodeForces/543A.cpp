#include<bits/stdc++.h>
using namespace std;
#define ll long long
int n, m, b, MOD, e;
ll dp[502][502], a[502];

int main() {
	cin >> n >> m >> b >> MOD;
	for (int i = 0; i < 502; ++i)
		dp[0][i] = 1;
	for (int i = 0; i < n; ++i) {
		cin >> e;
		for (int i = 1; i < 502; ++i)
			for (int j = e; j < 502; ++j)
				dp[i][j] = (dp[i][j] + dp[i - 1][j - e]) % MOD;
	}
	cout << dp[m][b] << endl;
}