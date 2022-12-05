#include <bits/stdc++.h>
using namespace std;
string s, t;
int T;
int main() {
    for (cin >> T; T--;) {
        cin >> s >> t;
        int p = t.size() - 1;
        for (int i = s.size() - 1; i >= 0; i--)~p && s[i] == t[p] ? p-- : i--;
        puts(~p ? "NO" : "YES");
    }
    return 0;
}
