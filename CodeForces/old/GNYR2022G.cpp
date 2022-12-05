#include<iostream>
#include<algorithm>
#define ll long long
using namespace std;
ll dp[40002][2];
const ll MOD = 1e6 + 7;

int main() {
	int n; cin >> n;
	if (n == 1) {
		cout << 1 << endl;
		return 0;
	}
	dp[2][0] = 1, dp[2][1] = 0;
	for (int i = 3; i <= n; ++i)
		dp[i][0] = (dp[i - 1][0] + dp[i - 1][1]) % MOD,
		dp[i][1] = (dp[i - 1][0]) % MOD;
	cout << (dp[n][0] + dp[n][1]) % MOD << endl;
}