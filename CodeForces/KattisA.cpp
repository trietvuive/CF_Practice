#include<bits/stdc++.h>
using namespace std;

void solve() {
    int i, n; cin >> i >> n;
    cout << i << ' ' << (n * (n + 1) / 2) + n << endl;
}
int main() {
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    int tc; cin >> tc;
    while(tc--) solve();
}
