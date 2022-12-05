#include<bits/stdc++.h>
using namespace std;
const int MAX_N = 1e5 + 2;
int dp[MAX_N], ar[MAX_N], n;


int main()
{
	cin >> n;
	for (int i = 0; i < n; ++i)
		cin >> ar[i];
	dp[0] = 0;
	for (int i = 0; i < n; ++i)
	{
		int small_ticket = upper_bound(ar, ar + i, ar[i] - 90) - ar;
		int large_ticket = upper_bound(ar, ar + i, ar[i] - 1440) - ar;
		dp[i+1] = min(dp[i] + 20, min(dp[small_ticket] + 50, dp[large_ticket] + 120));
	}
	for (int i = 1; i <= n; ++i)
		cout << dp[i] - dp[i-1] << endl;
}