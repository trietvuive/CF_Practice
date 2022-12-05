#include <bits/stdc++.h>
using namespace std;
int n, h, l, r, x, dp[2001][2001], sum, ans;
int main()
{
    cin >> n >> h >> l >> r;
    for (int i = 1; i <= n; i++)
    {
        cin >> x;
        sum += x;
        for (int j = 0; j <= i; j++)
        {
            if (j == 0) dp[i][j] = dp[i - 1][j];
            else dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - 1]);
            if (((sum - j) % h) <= r && ((sum - j) % h) >= l) dp[i][j]++;
            if (i == n) ans = max(ans, dp[i][j]);
        }
    }
    cout << ans;
}