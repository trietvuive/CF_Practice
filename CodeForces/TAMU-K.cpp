#include<bits/stdc++.h>
#define ll long long
using namespace std;

int N, M, K;
const int MOD = 1e9 + 7;
const int MAX = 250005;
int dp[MAX];
int b[17][3];

bool intersect(int x, int y) {
	for (int i = 0; i < K; ++i) {
		int xb = b[i][0], yb = b[i][1], lb = b[i][2];
		if (xb <= x && x <= xb + lb &&
			yb <= y && y <= yb + lb)
			return true;
	}
	return false;
}

int main() {
	cin >> N >> M >> K;
	for (int i = 0; i < K; ++i)
		for (int j = 0; j < 3; ++j)
			cin >> b[i][j];
	dp[0] = 1;
	for (int i = 0; i <= N; ++i)
	{
		for (int j = 0; j <= M; ++j)
		{
			if (intersect(i, j))
				dp[j] = 0;
			else
				dp[j] = (dp[j] + (j > 0 ? dp[j - 1] : 0)) % MOD;
		}
	}

	ll ans = dp[M];
	ans = (ans * ans) % MOD;
	cout << ans << endl;
}