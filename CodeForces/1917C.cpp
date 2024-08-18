#include<bits/stdc++.h>
#define endl '\n'
using namespace std;

using ll = long long;
using graph = vector<vector<int>>;
constexpr ll MOD = 1e9 + 7;


void solve() {
  int n,k,d;
  cin >> n >> k >> d;
  vector<int> a(n), v(k);

  int ans = 0, cnt = 0;

  for(int i = 0; i < n; ++i)
    cin >> a[i], cnt += a[i] == (i+1);
  for(int i = 0; i < k; ++i)
    cin >> v[i];

  --d;
  ans = cnt + d/2;

  for(int i = 0; i < 2*n && d > 0; ++i) {
    int b = v[i % k];
    cnt = 0, --d;
    for(int j = 0; j < b; ++j) ++a[j];
    for(int j = 0; j < n; ++j) cnt += a[j] == (j+1);
    ans = max(ans, cnt + d/2);
  }

  cout << ans << endl;
}

int main() {
  ios::sync_with_stdio(false); cin.tie(nullptr);
  int tc; cin >> tc;
  while(tc--) solve();
}

