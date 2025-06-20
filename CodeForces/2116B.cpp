#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using graph = vector<vector<int>>;

ll MOD = 998244353;

int binary_exp(int ex) {
  ll res = 1;
  ll a = 2;
  while(ex) {
    if(ex & 1) res = (res * a) % MOD;
    a = a * a % MOD;
    ex >>= 1;
  }
  return res;
}

int binary_sum(int a, int b) {
  return (binary_exp(a) + binary_exp(b)) % MOD;
}

void solve() {
	int n; cin >> n;
  vector<int> p(n, 0), q(n, 0);

  for(int i = 0; i < n; ++i) cin >> p[i];
  for(int i = 0; i < n; ++i) cin >> q[i];

  int maxp = 0, maxpidx = 0, maxq = 0, maxqidx = 0;
  for(int i = 0; i < n; ++i) {
    if(p[i] > maxp) maxp = p[i], maxpidx = i;
    if(q[i] > maxq) maxq = q[i], maxqidx = i;

    if(maxp > maxq || (maxp == maxq && q[i - maxpidx] > p[i - maxqidx])) cout << binary_sum(maxp, q[i - maxpidx]);
    else cout << binary_sum(maxq, p[i - maxqidx]);
    cout << " ";
  }
  cout << endl;
}

int main() {
	ios::sync_with_stdio(false), cin.tie(nullptr);
	int tc = 1; cin >> tc;
	while(tc--) solve();
}
