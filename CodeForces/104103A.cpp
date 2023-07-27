#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using graph = vector<vector<int>>;

void solve() {
	string a; cin >> a;
	map<char, int> mp;
	for (char c : a) {
		if(++mp[c] > a.size() / 2) {
			cout << "IMPOSSIBLE" << endl;
			return;
		}
	}

	vector<pair<int, char>> v;
	for (auto& p : mp) {
		v.push_back({p.second, p.first});
	}
	sort(v.begin(), v.end());

	string b,c;
	for(int i = v.size() - 1; i >= 0; --i) {
		int j = (i - 1 + v.size()) % v.size();
		b += string(v[i].first, v[i].second);
		c += string(v[j].first, v[j].second);
	}
	cout << b << '\n' << c << '\n';
}

int main() {
	ios::sync_with_stdio(false), cin.tie(nullptr);
	int tc = 1;
	while(tc--) solve();
}

