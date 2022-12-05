#include<bits/stdc++.h>
using namespace std;
int n, q, l, r, a[5005], f[5005][5005], dp[5005][5005];

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i)
		scanf("%d", a + i);
	for (int i = n; i >= 1; --i)
		for (int j = 1; j <= n; ++j)
			f[i][j] = i == j ? a[i] : f[i][j - 1] ^ f[i + 1][j],
			dp[i][j] = max(max(dp[i][j - 1], dp[i + 1][j]), f[i][j]);
	scanf("%d", &q);
	for (int i = 1; i <= q; ++i)
		scanf("%d%d", &l, &r), printf("%d\n", dp[l][r]);
}
