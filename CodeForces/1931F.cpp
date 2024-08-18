#include<bits/stdc++.h>
#define endl '\n'
using namespace std;

using ll = long long;
using graph = vector<vector<int>>;
constexpr ll MOD = 1e9 + 7;

bool detect_cycle_util(graph& g, vector<int>& visited, vector<int>& rec_stack, int current_node) {
  if(rec_stack[current_node])
    return true;
  if(visited[current_node])
    return false;

  visited[current_node] = true;
  rec_stack[current_node] = true;
  for(int child : g[current_node])
    if(detect_cycle_util(g, visited, rec_stack, child))
      return true;

  rec_stack[current_node] = false;
  return false;
}

bool detect_cycle(graph& g) {
  int n = g.size();
  vector<int> visited(n, false), rec_stack(n, false);

  for(int i = 1; i < n; ++i)
    if(detect_cycle_util(g, visited, rec_stack, i))
      return true;

  return false;
}

void solve() {
  int n, k; cin >> n >> k;
  graph g(n+1);

  for(int i = 0; i < k; ++i) {
    int prev; cin >> prev;
    if(n > 1) cin >> prev;
    for(int j = 2; j < n; ++j) {
      int curr; cin >> curr;
      g[prev].push_back(curr);
      prev = curr;
    }
  }

  if(detect_cycle(g))
    cout << "NO" << endl;
  else cout << "YES" << endl;
}

int main() {
  ios::sync_with_stdio(false); cin.tie(nullptr);
  int tc; cin >> tc;
  while(tc--) solve();
}

