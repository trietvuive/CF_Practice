#include<bits/stdc++.h>
#define endl '\n'
using namespace std;

using ll = long long;
using graph = vector<vector<int>>;
constexpr ll MOD = 1e9 + 7;


void solve() {
  int n; cin >> n;
  string s, ans; cin >> s;

  int rx = 0, ry = 0, hx = 0, hy = 0;
  bool used_rover = false, used_helicopter = false;
  for(char c : s) {
    if(c == 'N' || c == 'S') {
      if(ry == hy)
        ans += used_rover ? 'H' : 'R';
      else
        ans += (hy > ry) ^ (c == 'N') ? 'H' : 'R';
    } else {
      if(rx == hx)
        ans += used_rover ? 'H' : 'R';
      else
        ans += (hx > rx) ^ (c == 'E') ? 'H' : 'R';
    }

    if(ans.back() == 'R') {
      if(c == 'N') ry++;
      if(c == 'S') ry--;
      if(c == 'E') rx++;
      if(c == 'W') rx--;
      used_rover = true;
    } else {
      if(c == 'N') hy++;
      if(c == 'S') hy--;
      if(c == 'E') hx++;
      if(c == 'W') hx--;
      used_helicopter = true;
    }
  }

  if(!used_rover || !used_helicopter || rx != hx || ry != hy) {
    cout << "NO" << endl;
  } else {
    cout << ans << endl;
  }
}

int main() {
  ios::sync_with_stdio(false); cin.tie(nullptr);
  int tc = 1; cin >> tc;
  while(tc--) solve();
}

