#include<bits/stdc++.h>
using namespace std;

bool reverse(const string& a, const string& b) {
    for(int i = 0; i < a.size(); ++i)
        if(a[i] == b[i]) return false;

    return true;
}

int count_zero(const string& s) {
    int cnt = 0;
    for(int i = 0; i < s.size(); ++i)
        if(s[i] == '0') cnt++;

    return cnt;
}

void solve() {
    int n; 
    string a, b;
    cin >> n >> a >> b;

    bool reversible = reverse(a, b);
    if(a != b && !reversible) {
        cout << "NO" << '\n';
        return;
    }

    cout << "YES" << '\n';
    int cnt, zero_cnt = count_zero(b);
    if(zero_cnt == 0)
        cnt = 2 + reversible;
    else 
        cnt = zero_cnt + 1 + reversible + (zero_cnt % 2 == 0);

    cout << cnt << '\n';
    if(reversible) cout << 1 << ' ' << n << '\n';

    if(zero_cnt == 0) {
        cout << 1 << ' ' << 1 << '\n';
        cout << 2 << ' ' << n << '\n';
    }
    else {
        for(int i = 0; i < n; ++i) {
            if(b[i] == '0') cout << i+1 << ' ' << i+1 << '\n';
        }
        if(zero_cnt % 2)
            cout << 1 << ' ' << n << '\n';
        else {
            cout << 1 << ' ' << 1 << '\n';
            cout << 2 << ' ' << n << '\n';
        }
    }
    
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int tc; cin >> tc;
    while(tc--) {
        solve();
    }
}
