
#include<vector>
#include<string>
#include<iostream>

using namespace std;


int longestPrefix(string const& s) {
    int n = s.size();
    vector<int> pi(n, 0);

    for(int i = 1; i < n; ++i) {
        int j = pi[i-1];
        while(j > 0 && s[j] != s[i]) j = pi[j-1];
        if(s[i] == s[j]) ++j;
        pi[i] = j;
    }
    return pi[n-1];
}
void solve(string const& s) {
    int k = 0, n = s.size();
    while(k < n-1-k && s[k] == s[n-1-k]) ++k;

    int left = k, len = n-2*k;
    string w = s.substr(left, len), w_rev = string(w.rbegin(), w.rend());
    int longest_pre = longestPrefix(w + '#' + w_rev);
    int longest_suf = longestPrefix(w_rev + '#' + w);
    string ans, mid;
    if(longest_pre > longest_suf) mid = s.substr(left, longest_pre);
    else mid = s.substr(left + len - longest_suf, longest_suf);

    if(k == 0) ans = mid;
    else ans = s.substr(0, k) + mid + s.substr(n-k, k);
    cout << ans << endl;

}
int main() {
    int tc; cin >> tc;
    for(int i = 0; i < tc; ++i) {
        string s;
        cin >> s;
        solve(s);
    }
}
