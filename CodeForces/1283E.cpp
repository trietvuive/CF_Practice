#include<bits/stdc++.h>
using namespace std;
int a[200002], n;

int main() {
	cin >> n;
	for (int i = 0; i < n; ++i) cin >> a[i];
	sort(a, a + n);
	int maxv = -2, minv = -2, mn = 0, mx = 0;
	for (int i = 0; i < n; ++i) {
		if (minv < a[i] - 1)
			++mn, minv = a[i] + 1;
		if (maxv < a[i] + 1)
			++mx, maxv = max(maxv + 1, a[i] - 1);
	}
	cout << mn << " " << mx << endl;
}