#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using graph = vector<vector<int>>;
constexpr ll MOD = 1e9 + 7;


void solve() {
  ll n,m,q; cin >> n >> m >> q;
  vector<ll> a(n), b(m), g(n+m+1);

  for(int i = 0; i < n; i++) cin >> a[i];
  for(int i = 0; i < m; ++i) cin >> b[i];

  sort(a.begin(), a.end(), greater<int>());
  sort(b.begin(), b.end(), greater<int>());
  for(int i = 0, j = 0; i < n || j < m;) {
    if(j == m || i < n && a[i] > b[j]) ++i;
    else ++j;
    g[i+j] = i;
  }

  for(int i = 1; i < n; ++i) a[i] += a[i-1];
  for(int i = 1; i < m; ++i) b[i] += b[i-1];

  for(int i = 0; i < q; ++i) {
    ll x,y,z; cin >> x >> y >> z;
    ll k = min(x, g[z]);
    ll pa, pb;

    if(k+y >= z) pa = k, pb = z-k;
    else pb = y, pa = z-y;

    cout << (pa ? a[pa-1] : 0) + (pb ? b[pb-1] : 0) << '\n';
  }
}

int main() {
  ios::sync_with_stdio(false); cin.tie(nullptr);
  int tc = 1; cin >> tc;
  while(tc--) solve();
}
