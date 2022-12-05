#include<bits/stdc++.h>
using namespace std;

int ar[105];
void solve() {
	int n; cin >> n;
	map<int, char> mapping;
	for(int i = 0; i < n; ++i) {
		cin >> ar[i];
	}

	string s; cin >> s;

	for(int i = 0; i < n; ++i) {
		if(mapping.find(ar[i]) == mapping.end())
			mapping[ar[i]] = s[i];

		if(mapping[ar[i]] != s[i]) {
			cout << "NO" << '\n';
			return;
		}
	}

	cout << "YES" << '\n';
}

int main() {
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	int tc; cin >> tc;
	while(tc--) solve();
}
