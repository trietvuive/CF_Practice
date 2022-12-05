#include <bits/stdc++.h>

using namespace std;
int x[300], y[300], z[300], f[300][300][300];
int main()
{
    int r, b, g, i, j, n, k;
    cin >> r >> g >> b;


    for (i = 1; i <= r; i++)  cin >> x[i];
    for (i = 1; i <= g; i++)  cin >> y[i];
    for (i = 1; i <= b; i++)  cin >> z[i];

    sort(x + 1, x + r + 1); sort(y + 1, y + g + 1); sort(z + 1, z + b + 1);
    int res = 0;
    for (i = r; i >= 0; i--)
        for (j = g; j >= 0; j--)
            for (k = b; k >= 0; k--)
            {
                f[i][j][k] = max(f[i + 1][j + 1][k] + x[i + 1] * y[j + 1], 
                    max(f[i + 1][j][k + 1] + x[i + 1] * z[k + 1], max(f[i][j + 1][k + 1] + y[j + 1] * z[k + 1], 0)));

                res = max(res, f[i][j][k]);
            }
    cout << res;
    return 0;
}