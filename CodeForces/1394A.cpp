#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int MAX = 1e5 + 2;
ll a[MAX], d, m, n, cum[MAX];

int main() {
	cin >> n >> d >> m;
	for (int i = 0; i < n; ++i)
		cin >> a[i];
	sort(a, a + n);
	for (int i = 0; i < n; ++i)
		cum[i + 1] = cum[i] + a[i];

	int k = upper_bound(a, a + n, m) - a;
	ll ans = 0;
	for (int nlo = 0; nlo <= k; ++nlo) {
		int nhg = (n - nlo + d) / (d + 1);
		if (nhg <= n - k) {
			ans = max(ans, cum[n] - cum[n - nhg] + cum[k] - cum[k - nlo]);
		}
	}
	cout << ans << endl;
}