#include<bits/stdc++.h>
#define endl "\n"

using namespace std;

using ll = long long;
using graph = vector<vector<int>>;
constexpr ll MOD = 1e9 + 7;

int last(const string& s, int& idx, int k) {
  int ans = -1;
  vector<int> exists(k, false);
  while(idx < s.size() && k) {
    if(!exists[s[idx] - 'a'])
      --k, ans = s[idx];
    exists[s[idx] - 'a'] = true;
    ++idx;
  }

  for(int i = 0; i < exists.size(); ++i)
    if(!exists[i])
      return -('a' + i);
  return ans;
}

void solve() {
  int n,k,m; cin >> n >> k >> m;
  string s; cin >> s;
  string ans;

  bool possible = true;
  int idx = 0;
  for(int i = 0; i < n; ++i) {
    int last_char = last(s,  idx, k);
    if(last_char < 0) {
      possible = false;
      ans += (char)-last_char;
      break;
    } else
      ans += (char)last_char;
  }

  if(possible)
    cout << "YES" << endl;
  else {
    cout << "NO" << endl;
    for(int i = ans.size(); i < n; ++i)
      ans += 'a';
    cout << ans << endl;
  }
}

int main() {
  ios::sync_with_stdio(false); cin.tie(nullptr);
  int tc; cin >> tc;
  while(tc--) solve();
}

