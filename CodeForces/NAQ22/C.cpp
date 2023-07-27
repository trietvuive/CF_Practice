#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using graph = vector<vector<int>>;

void solve() {
	string a, b;
	cin >> a >> b;

	map<char, int> cnt;
	for(char c : a) ++cnt[c];
	for(char c : b) ++cnt[c];

	for(auto iter : cnt) 
		cout << string(iter.second, iter.first);
	cout << '\n';
}

int main() {
	ios::sync_with_stdio(false), cin.tie(nullptr);
	int tc = 1;
	while(tc--) solve();
}

