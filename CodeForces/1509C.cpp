/*#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int MAX = 2e3 + 5;
ll dp[MAX][MAX], a[MAX];

ll solve(int left, int right)
{
	if (dp[left][right] != -1)
		return dp[left][right];
	if (left == right)return 0;
	return dp[left][right] = a[right] - a[left] + min(solve(left + 1, right), solve(left, right - 1));
}
int main()
{
	int n;
	cin >> n;
	for (int i = 0; i < n; ++i)
		cin >> a[i];
	sort(a, a+n);
	memset(dp, -1, sizeof dp);
	cout << solve(0, n - 1) << endl;
}
*/