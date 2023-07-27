#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using graph = vector<vector<int>>;

bool heatable(int mask, vector<int> stalls, const vector<vector<int>>& conditioners) {
	for(int i = 0; i < conditioners.size(); ++i) {
		if(mask & (1 << i)) {
			for(int left = conditioners[i][0]; left <= conditioners[i][1]; ++left) {
				stalls[left] -= conditioners[i][2];
			}
		}
	}

	for(int i = 1; i < stalls.size(); ++i) {
		if(stalls[i] > 0) {
			return false;
		}
	}
	return true;
}

void solve() {
	int n, m; cin >> n >> m;

	vector<int> stalls(101, 0);
	vector<vector<int>> conditioners(m);
	for (int i = 1; i <= n; i++) {
		int s,t,c; cin >> s >> t >> c;
		for(;s <= t; ++s)
			stalls[s] = max(stalls[s], c);
	}

	for (int i = 0; i < m; i++) {
		int a,b,p,m; cin >> a >> b >> p >> m;
		conditioners[i] = {a,b,p,m};
	}

	int cost = 1e9;
	for(int mask = 0; mask < (1 << m); ++mask) {
		int sum = 0;
		for(int j = 0; j < m; ++j) {
			if(mask & (1 << j)) {
				sum += conditioners[j][3];
			}
		}

		if(heatable(mask, stalls, conditioners)) {
			cost = min(cost, sum);
		}
	}

	cout << cost << endl;
}

int main() {
	ios::sync_with_stdio(false), cin.tie(nullptr);
	int tc = 1;
	while(tc--) solve();
}

