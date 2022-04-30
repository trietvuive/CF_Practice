#include <iostream>
using namespace std;
int c[3], y[3], m[3], k[3], mn[4];
int main() {
    int tc; cin >> tc;
    for (int i = 1; i <= tc; ++i) {
        for (int j = 0; j < 3; ++j)
            cin >> c[j] >> y[j] >> m[j] >> k[j];
        mn[0] = mn[1] = mn[2] = mn[3] = 1e9;
        for (int j = 0; j < 3; ++j)
            mn[0] = min(mn[0], c[j]),
            mn[1] = min(mn[1], y[j]),
            mn[2] = min(mn[2], m[j]),
            mn[3] = min(mn[3], k[j]);
        printf("Case #%d: ", i); 
        int total = mn[0] + mn[1] + mn[2] + mn[3];
        if (total < 1e6)
            printf("IMPOSSIBLE\n");
        else {
            for (int j = 0; j < 4; ++j)
            {
                total -= mn[j], mn[j] = 0;
                if (total < 1e6) mn[j] = 1e6 - total, total = 1e6;
            }
            printf("%d %d %d %d\n", mn[0], mn[1], mn[2], mn[3]);
        }
    }
}