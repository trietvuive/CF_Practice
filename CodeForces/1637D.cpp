#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n, m, t, a[110], b[110];
bitset<10010> f;
int main() {
	cin >> t;
	while (t--) {
		cin >> n;
		ll sum = 0, s = 0, mn = 1e9;
		f.reset(); f[0] = 1;
		for (int i = 0; i < n; ++i)
			cin >> a[i], sum += a[i]*a[i], s += a[i];
		for (int i = 0; i < n; ++i)
			cin >> b[i], sum += b[i] * b[i], s += b[i];
		for (int i = 0; i < n; ++i) f = (f << a[i]) | (f << b[i]);
		for (int i = 1; i <= s; ++i)
			if (f[i]) mn = min(mn, (s - i) * (s - i) + i * i);
		cout << mn + (n - 2) * sum << endl;
	}
}