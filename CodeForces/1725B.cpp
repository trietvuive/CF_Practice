#include<bits/stdc++.h>
#define ll long long
using namespace std;

ll n,d,a[100002];

void solve() {
	cin >> n >> d;
	for(int i = 0; i < n; ++i)
		cin >> a[i];
	sort(a, a+n);
	ll ans = 0;
	for(int i = n-1; i >= 0; --i)
		if(a[i] * n > d) ++ans, n -= (d/a[i]) + 1;
	cout << ans << endl;
}

int main() {
	ios_base::sync_with_stdio(false), cin.tie(NULL);
	solve();
}
