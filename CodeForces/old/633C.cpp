#include<string>
#include<iostream>
#include<vector>
#include<algorithm>
#define ll long long
using namespace std;

const ll p = 31, MOD = 1e9 + 9, MXLEN = 10002;
ll ppow[MXLEN], hash_word[MXLEN], partial_hash[MXLEN];

int main() {
    string s, w;
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ppow[0] = 1;
    for(int i = 1; i < MXLEN; ++i) ppow[i] = (ppow[i-1] * p) % MOD;

    int n; cin >> n;
    cin >> s;
    reverse(s.begin(), s.end());
    for(int i = 0; i < n; ++i)
        partial_hash[i+1] = (partial_hash[i] + (s[i] - 'a' + 1) * ppow[i]) % MOD;

    int m; cin >> m;
    vector<string> words;
    for(int i = 0; i < m; ++i) {
        cin >> w;
        ll hash = 0;
        for(int j = 0; j < w.size(); ++j)
            hash = (hash + (tolower(w[j]) - 'a' + 1) * ppow[j]) % MOD;
        words.push_back(w);
        hash_word[i] = hash;
    }
    vector<ll> dp(n+1, -1);
    dp[0] = 1;
    for(int i = 1; i <= n; ++i) {
        for(int j = 0; j < m; ++j) {
            int word_size = words[j].size();
            if(word_size > i || dp[i - word_size] == -1) continue;
            ll cur_h = (partial_hash[i] + MOD - partial_hash[i - word_size]) % MOD;
            ll shift_hash = hash_word[j] * ppow[i - word_size] % MOD;
            if(cur_h == shift_hash)
                dp[i] = j;
        }
    }

    vector<string> ans;
    int index = n;
    while(index > 0) {
        ans.push_back(words[dp[index]]);
        index -= words[dp[index]].size();
    }
    for(auto const& s : ans)
        cout << s << ' ';
    cout << endl;
}
