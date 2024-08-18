#include<bits/stdc++.h>
#define endl '\n'
using namespace std;

using ll = long long;
using graph = vector<vector<int>>;
constexpr ll MOD = 1e9 + 7;

int zero_count(const string& s) {
  int zero = 0;
  for(int i = s.size() - 1; i >= 0; --i)
    if(s[i] == '0') ++zero;
    else break;
  return zero;
}

void solve() {
  int n, m; cin >> n >> m;
  int sm = 0;
  vector<int> zeros;

  for(int i = 0; i < n; ++i) {
    string s; cin >> s;
    int zero = zero_count(s);

    if(zero > 0)
      zeros.push_back(zero);
    sm += s.size();
  }

  sort(zeros.begin(), zeros.end());
  for(int i = zeros.size() - 1; i >= 0; i -= 2) {
    sm -= zeros[i];
  }

  if(sm > m) cout << "Sasha" << endl;
  else cout << "Anna" << endl;
}

int main() {
  ios::sync_with_stdio(false); cin.tie(nullptr);
  int tc; cin >> tc;
  while(tc--) solve();
}

