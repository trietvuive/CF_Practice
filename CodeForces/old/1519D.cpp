#include<bits/stdc++.h>
using namespace std;
const int MAXN = 5005;
#define ll long long
ll a[MAXN], b[MAXN];
ll dp[MAXN][MAXN];
int main()
{
	int n;
	cin >> n;
	ll init = 0, mx = 0;
	for (int i = 1; i <= n; ++i)cin >> a[i];
	for (int i = 1; i <= n; ++i)cin >> b[i], init += a[i] * b[i];
	for (int l = n; l >= 1; --l)
	{
		for (int r = l+1; r <= n; ++r)
		{
			dp[l][r] = dp[l + 1][r - 1] - a[l] * b[l] - a[r] * b[r] + a[l] * b[r] + a[r] * b[l];
			mx = max(mx, dp[l][r]);
		}
	}
	cout << mx + init << endl;

}
