#include<bits/stdc++.h>
const int MX = 5005;
int dp[MX][MX][2], a[MX], n;

using namespace std;

int main() {
    cin >> n;
    for(int i = 1; i <= n; ++i) cin >> a[i];

    memset(dp, 0x3f, sizeof dp);

    dp[0][0][0] = dp[1][0][0] = dp[1][1][1] = 0;
    for(int i = 2; i <= n; ++i) {
        dp[i][0][0] = dp[i-1][0][0];

        for(int k = 1, end = (i+1) / 2; k <= end; ++k) {
            dp[i][k][0] = min(dp[i-1][k][0], dp[i-1][k][1] + max(0, a[i] - a[i-1] + 1));
            int apart = dp[i-2][k-1][1] + max(0, max(a[i-1] - a[i-2] + 1, a[i-1] - a[i] + 1));
            dp[i][k][1] = min(dp[i-1][k-1][0] + max(0, a[i-1] - a[i] + 1), apart);
        }
    }

    for(int k = 1, end = (n+1) / 2; k <= end; ++k)
        cout << min(dp[n][k][0], dp[n][k][1]) << ' ';
    cout << endl;
}

