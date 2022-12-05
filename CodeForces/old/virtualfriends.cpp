#include<bits/stdc++.h>
using namespace std;

int dsu[100005], sz[100005];

int find(int x){
	if(dsu[x] == x) return x;
	return dsu[x] = find(dsu[x]);
}

int get_size(int x){
	return sz[find(x)];
}

void merge(int x, int y){
	x = find(x);
	y = find(y);
	if(x == y) return;
	if(sz[x] < sz[y]) swap(x, y);
	dsu[y] = x;
	sz[x] += sz[y];
}

void solve() {
	int f; cin >> f;
	unordered_map<string, int> mp;
	int cur_idx = 0;
	for(int i = 0; i < f; ++i) {
		string a, b; cin >> a >> b;
		if(mp.find(a) == mp.end()) mp[a] = cur_idx, dsu[cur_idx] = cur_idx, sz[cur_idx] = 1, cur_idx++;
		if(mp.find(b) == mp.end()) mp[b] = cur_idx, dsu[cur_idx] = cur_idx, sz[cur_idx] = 1, cur_idx++;

		merge(mp[a], mp[b]);
		cout << get_size(mp[a]) << '\n';
	}
}

int main() {
	ios::sync_with_stdio(false), cin.tie(nullptr);
	int tc; cin >> tc;
	while(tc--) solve();
}
