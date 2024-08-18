#include<bits/stdc++.h>
#define endl '\n'
using namespace std;

using ll = long long;
using graph = vector<vector<int>>;
constexpr ll MOD = 1e9 + 7;


void solve() {
  ll h,w,r1,c1,r2,c2;
  cin >> h >> w >> r1 >> c1 >> r2 >> c2;

  ll rdist = r2 - r1, cdist = abs(c1 - c2);
  ll k = (rdist + 1) / 2;

  if(cdist > rdist) cout << "Draw" << endl;
  else if(rdist % 2) {
    if(cdist <= 1 ||
      (c1 < c2 ? w - c1 : c1 - 1) <= k)
      cout << "Alice" << endl;
    else cout << "Draw" << endl;
  } else {
    if(c1 == c2 ||
      (c1 < c2 ? c2 - 1 : w - c2) <= k)
      cout << "Bob" << endl;
    else cout << "Draw" << endl;
  }
}

int main() {
  ios::sync_with_stdio(false); cin.tie(nullptr);
  int tc; cin >> tc;
  while(tc--) solve();
}

