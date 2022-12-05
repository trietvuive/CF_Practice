#include<bits/stdc++.h>
using namespace std;

void solve() {
    int n; cin >> n;
    int ans = 0;
    for(int i = 0; i < n; ++i) {
        string s; cin >> s;
        for(char& c : s) c = tolower(c);

        if(s.find("pink") != string::npos || s.find("rose") != string::npos) ++ans;
    }
    if(ans == 0) cout << "I must watch Star Wars with my daughter\n";
    else cout << ans << '\n';
}
int main() {
    ios::sync_with_stdio(false), cin.tie(NULL);
    solve();
}
