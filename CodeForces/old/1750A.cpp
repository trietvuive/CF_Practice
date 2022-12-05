#include<bits/stdc++.h>
using namespace std;

void solve() {
    int n; cin >> n;
    int mn = INT_MAX, first = -1;
    for(int i = 0; i < n; ++i) {
        int x; cin >> x;
        mn = min(mn, x);
        if(i == 0) first = x;
    }

    if(first == mn)
        cout << "YES" << '\n';
    else
        cout << "NO" << '\n';
}

int main() {
    int tc; cin >> tc;
    while(tc--) solve();
}
