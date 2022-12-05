#include<bits/stdc++.h>
using namespace std;
string a, b;

void solve() {
	cin >> a >> b;
	int n = a.size() - 1, m = b.size() - 1;

	unordered_set<char> banned;
	while(n >= 0 && m >= 0) {
		if(banned.find(b[m]) != banned.end()) break;
		if(a[n] == b[m]) --m, --n;
		else banned.insert(a[n]), --n;
	}

	if(m == -1) cout << "YES" << '\n';
	else cout << "NO" << '\n';
}

int main() {
	ios::sync_with_stdio(false), cin.tie(nullptr);
	int t; cin >> t;
	while(t--) solve();
}
