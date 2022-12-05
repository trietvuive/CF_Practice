#include<bits/stdc++.h>
int n, p[1 << 17], d[1 << 17], s[1 << 17], a;
main() {
    scanf("%d", &n);
    for(int i = 2; i <= n; ++i)
        scanf("%d", &p[i]);
    for(int i = 1; i <=n; ++i)
        s[d[i] = d[p[i]] + 1] ^= 1;
    for(int i = 1; i <= n; ++i)
        a += s[i];
    printf("%d", a);
}