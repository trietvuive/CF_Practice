#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int MAX = 3e5 + 2;
ll a[MAX], b[MAX], dp[MAX][3], n, q;

int main() {
	scanf("%lld", &q);
	while (q--) {
		scanf("%lld", &n);
		for (int i = 1; i <= n; ++i)
			scanf("%lld %lld", &a[i], &b[i]);
		dp[1][0] = 0, dp[1][1] = b[1], dp[1][2] = b[1] * 2;
		for (int i = 2; i <= n; ++i) {
			dp[i][0] = dp[i][1] = dp[i][2] = LLONG_MAX;
			for (int dleft = 0; dleft <= 2; ++dleft)
				for (int dright = 0; dright <= 2; ++dright)
					if (a[i - 1] + dleft != a[i] + dright)
						dp[i][dright] = min(dp[i][dright], dp[i - 1][dleft] + b[i] * dright);
		}

		cout << min(dp[n][0], dp[n][1]) << endl;
	}
}