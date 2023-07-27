#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using graph = vector<vector<int>>;
using pii = pair<int,int>;

int a[500005];
int count_win(map<int, int>& mp, int m) {
	int win_count = 0;
	for(auto& pair : mp) {
		if(m >= pair.first * pair.second)
			m -= pair.first * pair.second, win_count += pair.second;
		else {
			win_count += m / pair.first;
			break;
		}
	}
	return win_count;
}

void solve() {
	int n,m; cin >> n >> m;
	map<int, int> mp;
	for(int i = 1; i <= n; ++i) {
		cin >> a[i];
		++mp[a[i]];
	}

	int max_win = count_win(mp, m);
	if(max_win == n) {
		cout << 1 << '\n';
		return;
	}
	int critical_idx = max_win + 1, critical_rank = n - max_win;
	m -= a[critical_idx], --mp[a[critical_idx]];

	if(m < 0) {
		cout << critical_rank + 1 << '\n';
		return;
	}

	int crit_win = count_win(mp, m) + 1;

	if(crit_win == max_win) 
		cout << critical_rank << '\n';
	else
		cout << critical_rank + 1 << '\n';
}

int main() {
	ios::sync_with_stdio(false), cin.tie(nullptr);
	int tc;
	cin >> tc;
	while(tc--) solve();
}

