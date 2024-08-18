#include<bits/stdc++.h>
#define endl '\n'
using namespace std;

using ll = long long;
using graph = vector<vector<int>>;
constexpr ll MOD = 998244353;

vector<ll> fact;

ll pow_mod(ll a, ll b, ll mod) {
  ll res = 1;
  while(b) {
    if(b & 1) res = res * a % mod;
    a = a * a % mod;
    b >>= 1;
  }
  return res;
}

ll inv(ll a, ll mod) {
  return pow_mod(a, mod - 2, mod);
}

ll nCk(int n, int k) {
  ll res = fact[n];
  res = res * inv(fact[k], MOD) % MOD;
  res = res * inv(fact[n - k], MOD) % MOD;
  return res;
}

ll calc(ll a, ll b, ll c, ll d) {
  return nCk(a+c-1, c) * nCk(b+d-1, d) % MOD;
}


void solve() {
  ll a, b, c, d;
  cin >> a >> b >> c >> d;

  if(a + b == 0)
    cout << (c == 0 || d == 0) << endl;
  else if(abs(a - b) > 1)
    cout << 0 << endl;
  else {
    ll res = 0;
    if(a <= b)
      res = (res + calc(a+1, b, c, d)) % MOD;
    if(b <= a)
      res = (res + calc(a, b+1, c, d)) % MOD;
    cout << res << endl;
  }
}

int main() {
  for(ll i = 0; i <= 4e6 + 5; ++i)
    fact.push_back(i ? fact.back() * i % MOD : 1);

  ios::sync_with_stdio(false); cin.tie(nullptr);
  int tc; cin >> tc;
  while(tc--) solve();
}

