#include<bits/stdc++.h>
#define endl '\n'
using namespace std;

using ll = long long;
using graph = vector<vector<int>>;
constexpr ll MOD = 1e9 + 7;


void solve() {
  ll a,b,r; cin >> a >> b >> r;
  if(b > a) swap(a, b);

  ll flip = 0;
  ll index = 62;
  for(; index >= 0; index--) {
    ll mask = 1ll << index;
    if((a & mask) > (b & mask)) break;
  }

  for(ll i = index - 1; i >= 0; --i) {
    ll mask = 1ll << i;
    if((a & mask) <= (b & mask) ||
       (flip | mask) > r)
      continue;

    flip |= mask;
    a ^= mask;
    b ^= mask;
  }
  cout << a-b << endl;
}

int main() {
  ios::sync_with_stdio(false); cin.tie(nullptr);
  int tc; cin >> tc;
  while(tc--) solve();
}

