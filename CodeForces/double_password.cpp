#include<bits/stdc++.h>
using namespace std;

void solve() {
	string a, b; cin >> a >> b;
	int ans = 1;
	for(int i = 0; i < 4; ++i) ans *= (a[i] != b[i] ? 2 : 1);
	cout << ans << '\n';
}


int main() {
	ios::sync_with_stdio(false), cin.tie(nullptr);
	solve();
}
