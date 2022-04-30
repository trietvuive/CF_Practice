#include <iostream>
#include <algorithm>

using namespace std;
const int MAX_N = 1e5 + 3;
int ar[MAX_N];
int main() {
    int tc; cin >> tc;
    for (int i = 1; i <= tc; ++i) {
        int n; cin >> n;
        for (int j = 1; j <= n; ++j)
            cin >> ar[j];
        sort(ar + 1, ar + n + 1);
        int straight = 0;
        for (int j = 1; j <= n; ++j)
            if (ar[j] >= j) ++straight;
        printf("Case #%d: %d\n", i, straight);
    }
}