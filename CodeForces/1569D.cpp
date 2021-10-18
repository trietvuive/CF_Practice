#include<bits/stdc++.h>
#include<unordered_map>
using namespace std;
#define ll long long
const int N = 2e5 + 2;
int ax[N], ay[N];
int main() {
    unordered_map<int, int> cnt_x, cnt_y;
    map<pair<int, int>, int> cnt_dup;
    int tc;
    cin >> tc; 
    while (tc --> 0) {
        ll ans = 0;
        int n, m, k;
        scanf("%d%d%d", &n, &m, &k); 
        cnt_x.clear(), cnt_y.clear(), cnt_dup.clear();
        for(int i = 1; i<=n; ++i)
            scanf("%d", &ax[i]);
        for(int i = 1; i<=m; ++i)
            scanf("%d", &ay[i]); 
        for(int i = 1; i<=k; ++i)
        {
            int x, y, idx;
            scanf("%d%d", &x, &y);
            idx = lower_bound(ax+1, ax+n+1, x) - ax; 
            if (ax[idx] == x)x = idx * 2; //raise flag, point is on x route. don't count incovenience
            else x = idx * 2 - 1, ans += (cnt_x[x]++);//inconvenient only if points are not on x route but have the same closest upper x route

            idx = lower_bound(ay + 1, ay + m + 1, y) - ay; 
            if (ay[idx] == y)y = idx * 2; //raise flag, point is on y route. don't count inconvenience
            else y = idx * 2 - 1, ans += (cnt_y[y]++);//inconvenient only if points are not on y route but have the same closest upper y route

            //point on the same x and y road is the same point
            //so it shouldn't be counted. only apply if we actually count inconvenience when checking x or y.
            if ((x | y) & 1)ans -= (cnt_dup[{x, y}]++);
        }
        printf("%lld\n", ans);
    }
}