#include<bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
	ll n; cin >> n;
	if(n % 2)
		cout << n/2 + 1 << '\n';
	else
		cout << n/2 << '\n';
}

int main() {
	ios::sync_with_stdio(false), cin.tie(nullptr);
	int tc; cin >> tc;	
	while(tc--) {
		solve();
	}
}
