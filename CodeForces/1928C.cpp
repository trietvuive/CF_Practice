#include<bits/stdc++.h>
#define endl '\n'
using namespace std;

using ll = long long;
using graph = vector<vector<int>>;
constexpr ll MOD = 1e9 + 7;

ll count_even_divisor(ll l, ll r, ll x) {
  unordered_set<ll> cnt;
  for(ll i = 1; i * i <= r; ++i) {
    ll k = (i+2)/2;
    if(l % i == 0) {
      if(i % 2 == 0 && k >= x) cnt.insert(i);

      ll rk = (l / i + 2)/2;
      if(l / i % 2 == 0 && rk >= x) cnt.insert(l / i);
    }
    if(r % i == 0) {
      if(i % 2 == 0 && k-1 >= x) cnt.insert(i);

      ll rk = (r / i + 2)/2;
      if(r / i % 2 == 0 && rk-1 >= x) cnt.insert(r / i);
    }
  }

  return cnt.size();
}

void solve() {
  ll x,n; cin >> n >> x;
  if(x > n) {
    cout << 0 << endl;
    return;
  }

  ll prev_cycle = n - x, next_cycle = n + x - 2;
  cout << count_even_divisor(prev_cycle, next_cycle, x) << endl;
}

int main() {
  ios::sync_with_stdio(false); cin.tie(nullptr);
  int tc; cin >> tc;
  while(tc--) solve();
}

