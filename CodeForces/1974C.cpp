#include<bits/stdc++.h>
#define endl '\n'
using namespace std;

using ll = long long;
using graph = vector<vector<int>>;
constexpr ll MOD = 1e9 + 7;


void solve() {
  map<pair<int,int>, map<int,int>> firstTwo, middleTwo, lastTwo;
  map<pair<int,int>, int> firstTwoCnt, middleTwoCnt, lastTwoCnt;
  int n; cin >> n;
  vector<int> a(n);
  for(int i = 0; i < n; ++i) cin >> a[i];

  ll ans = 0;
  for(int i = 2; i < n; ++i) {
    ans += firstTwoCnt[{a[i-2], a[i-1]}]++ - firstTwo[{a[i-2], a[i-1]}][a[i]]++;
    ans += middleTwoCnt[{a[i-2], a[i]}]++ - middleTwo[{a[i-2], a[i]}][a[i-1]]++;
    ans += lastTwoCnt[{a[i-1], a[i]}]++ - lastTwo[{a[i-1], a[i]}][a[i-2]]++;
  }

  cout << ans << endl;
}

int main() {
  ios::sync_with_stdio(false); cin.tie(nullptr);
  int tc; cin >> tc;
  while(tc--) solve();
}

