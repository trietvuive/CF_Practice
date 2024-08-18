#include<bits/stdc++.h>
#define endl '\n'
using namespace std;

using ll = long long;
using graph = vector<vector<int>>;
constexpr ll MOD = 1e9 + 7;


void solve() {
  ll k,x,a; cin >> k >> x >> a;
  --k;
  ll total = 0;
  for(int i = 0; i <= x; ++i) {
    ll bet = (total/k) + 1;
    if(a < bet) {
      cout << "NO\n";
      return;
    }
    a -= bet;
    total += bet;
  }
  cout << "YES\n";
}

int main() {
  ios::sync_with_stdio(false); cin.tie(nullptr);
  int tc; cin >> tc;
  while(tc--) solve();
}

