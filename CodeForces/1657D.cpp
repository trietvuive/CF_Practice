#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#define ll long long
using namespace std;

const int MAX = 1e6 + 2;
ll bst[MAX], n, C, ci, d, h, ans[MAX];
int main() {
    cin >> n >> C;
    for(int i = 0; i < n; ++i) {
        cin >> ci >> d >> h;
        bst[ci] = max(bst[ci], d*h);
    }

    for(int i = 1; i <= C; ++i) {
        bst[i] = max(bst[i], bst[i-1]);
        for(ll multiplier = 2; i * multiplier <= C; ++multiplier)
            bst[i*multiplier] = max(bst[i*multiplier], bst[i] * multiplier);
    }


    int m; cin >> m;
    for(int i = 0; i < m; ++i) {
        cin >> d >> h;
        int idx = upper_bound(bst, bst + C + 1, d*h) - bst;
        ans[i] = idx > C ? -1 : idx;
    }
    for(int i = 0; i < m; ++i) cout << ans[i] << ' ';
    cout << endl;
}
