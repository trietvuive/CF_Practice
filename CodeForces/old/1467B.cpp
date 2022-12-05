#include<bits/stdc++.h>
using namespace std;
int t, n, a[300005], k, s;
int f(int i) {
	if (a[i] > a[i - 1] && a[i] > a[i + 1]) return 1;
	if (a[i] < a[i - 1] && a[i] < a[i + 1]) return 1;
	return 0;
}

int main() {
	cin >> t;
	while (t--) {
		cin >> n; s = k = 0;
		for (int i = 1; i <= n; ++i) cin >> a[i];
		a[0] = a[1], a[n + 1] = a[n];
		for (int i = 2; i < n; ++i) {
			int p = 0, q = 0, w = a[i]; s += f(i);
			p = q = f(i - 1) + f(i) + f(i + 1);
			a[i] = a[i - 1]; p -= f(i + 1);
			a[i] = a[i + 1]; q -= f(i - 1);
			a[i] = w;
			k = max(k, max(p, q));
		}
		cout << s - k << endl;
	}
}