#include<bits/stdc++.h>
#define rep(i,a,b) for(int i = a; i <= b; ++i)
using namespace std;
const int N = 505;
#define int long long
int n, m, k, a[N][N], b[N][N], dp[N][N][11];

signed main() {
	cin >> n >> m >> k;
	rep(i, 1, n) rep(j, 1, m - 1)
		scanf("%lld", &a[i][j]);
	rep(i, 1, n - 1) rep(j, 1, m)
		scanf("%lld", &b[i][j]);

	memset(dp, 0x3f, sizeof(dp));
	rep(i, 1, n)rep(j, 1, m)dp[i][j][0] = 0;

	rep(t, 1, k / 2) rep(i, 1, n) rep(j, 1, m)
		dp[i][j][t] = min(min(dp[i - 1][j][t - 1] + b[i - 1][j], dp[i + 1][j][t - 1] + b[i][j]),
						  min(dp[i][j - 1][t - 1] + a[i][j - 1], dp[i][j + 1][t - 1] + a[i][j]));

	if (k & 1) {
		rep(i, 1, n) {
			rep(j, 1, m) printf("-1 ");
			putchar('\n');
		}
		return 0;
	}
	rep(i, 1, n) {
		rep(j, 1, m) printf("%lld ", dp[i][j][k / 2] * 2);
		putchar('\n');
	}
}