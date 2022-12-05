#include<bits/stdc++.h>

using ll = long long;
using namespace std;

void solve() {
    int n; string s; 
    cin >> n >> s;
    ll z = 0, o = 0, co = 0, cz = 0;
    ll ans = 0;
    for(int i = 0; i < n; ++i) {
        if(s[i] == '0') {
            ++z, ++cz;
            co = 0;
        } else {
            ++o, ++co;
            cz = 0;
        }
        ans = max(ans, max(cz * cz, co * co));
    }
    ans = max(ans, z * o);
    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--) {
        solve();
    }
}
