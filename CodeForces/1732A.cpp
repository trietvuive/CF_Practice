#include<bits/stdc++.h>
using namespace std;

int gcd(int a, int b) {
	if (b == 0) return a;
	return gcd(b, a % b);
}

int a[25], n;
void solve() {
	cin >> n;
	for(int i = 1; i <= n; ++i) cin >> a[i];
	int g = a[1];
	for(int i = 2; i <= n; ++i) g = gcd(g, a[i]);

	if(g == 1) cout << 0 << '\n';
	else if(gcd(g, n) == 1) cout << 1 << '\n';
	else if(n > 1 && gcd(g, n-1) == 1) cout << 2 << '\n';
	else cout << 3 << '\n';
}
int main() {
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	int tc; cin >> tc;
	while(tc--) solve();
}
