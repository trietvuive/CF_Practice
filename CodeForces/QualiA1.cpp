#include<bits/stdc++.h>

using namespace std;

bool solve() {
    int n,k,e;
    unordered_map<int,int> cnt;
    cin >> n >> k;
    for(int i = 0; i < n; ++i) {
        cin >> e;
        ++cnt[e];
    }

    if(2*k < n) return false;
    for(auto& iter : cnt)
        if(iter.second > 2) return false;
    return true;
}

int main() {
    freopen("in/sample.txt", "r", stdin);
    freopen("out/sample.txt", "w", stdout);
    ios::sync_with_stdio(0), cin.tie(0);
    int tc;
    cin >> tc;
    for(int i = 1; i <= tc; ++i) {
        bool valid = solve();
        if(valid)
            printf("Case #%d: YES\n", i);
        else
            printf("Case #%d: NO\n", i);
    }
}
