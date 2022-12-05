#include<bits/stdc++.h>
using namespace std;

void solve() {
	int n,k; cin >> n >> k;
	bool one_exist = false;
	for(int i = 0; i < n; ++i) {
		int x; cin >> x;
		if(x == 1) one_exist = true;
	}
	if(one_exist) cout << "YES" << '\n';
	else cout << "NO" << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin >> t;
	while(t--) {
		solve();
	}
}
