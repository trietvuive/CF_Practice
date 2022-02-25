#include<bits/stdc++.h>
using namespace std;
int i, n, k, x, v, t, ans, a[10010], b[10010], c[10010], f[10010];
int main() {
    scanf("%d %d", &n, &k);
    for (i = 1; i <= n; i++) scanf("%d", &a[i]), b[i] = (i <= k) ? a[i] : 0;
    for (t = k + 1; x < n;)
        for (v = x * 100.0 / n + 0.5, i = 1; i <= k; i++) {
            if (!b[i]) continue;
            c[i]++;
            if (c[i] == v && !f[i]) ans++, f[i] = 1;
            if (c[i] == b[i]) x++, f[i] = c[i] = 0, b[i] = a[t++];
        }
    printf("%d\n", ans);
    return 0;
}