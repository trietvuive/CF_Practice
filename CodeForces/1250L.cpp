#include<bits/stdc++.h>
#define endl '\n'
using namespace std;

using ll = long long;
using graph = vector<vector<int>>;
constexpr ll MOD = 1e9 + 7;


void solve() {
  int a,b,c; cin >> a >> b >> c;
  int avg = max({min(a,c), (a+b+c+2)/3, (max(a,c) + 1) / 2});
  cout << avg << endl;
}

int main() {
  ios::sync_with_stdio(false); cin.tie(nullptr);
  int tc; cin >> tc;
  while(tc--) solve();
}

