#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using graph = vector<vector<int> >;

void solve() {
	int n; cin >> n;
  ll ans = 0, series_sum = 0, last = 0;
  for(int i = 0; i < n; ++i) {
    ll element; cin >> element;
    if(last > element) series_sum += i;
    last = element;
    series_sum++;
    ans += series_sum;
  }
  cout << ans << '\n';
}

int main() {
	ios::sync_with_stdio(false), cin.tie(nullptr);
	int tc = 1; cin >> tc;
	while(tc--) solve();
}
