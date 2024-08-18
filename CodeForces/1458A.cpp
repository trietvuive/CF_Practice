#include<bits/stdc++.h>
#define endl '\n'
using namespace std;

using ll = long long;
using graph = vector<vector<int>>;
constexpr ll MOD = 1e9 + 7;


void solve() {
  ll n,m,a,g = 0,x;
  cin >> n >> m >> a;
  for(int i = 1; i < n; ++i)
    cin >> x, g = gcd(g, abs(x-a));
  for(int i = 0; i < m; ++i)
    cin >> x, cout << gcd(g, x+a) << ' ';
  cout << endl;
}

int main() {
  ios::sync_with_stdio(false); cin.tie(nullptr);
  int tc = 1;
  while(tc--) solve();
}

