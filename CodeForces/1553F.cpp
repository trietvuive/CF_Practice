#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 1e6 + 5;
ll z[N], s[N], x, n, c, a;
void add(int i, ll x, ll* a) { for (; i < N; i += i & -i) a[i] += x; }
ll qry(int i, ll* a, ll ret = 0) { for (; i; i -= i & -i) ret += a[i]; return ret; }
int main() {
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> x, a += x * i + c, c += x, a -= qry(x, s);
        for (int j = x; j + x < N; j += x) a -= (qry(j + x - 1, z) - qry(j - 1, z)) * j, add(j, x, s);
        add(x, 1, z); cout << a << ' ';
    }
    return 0;
}