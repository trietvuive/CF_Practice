#include<bits/stdc++.h>
using namespace std;

int a[100002], b[100002], n, m;
int main() {
	ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
	cin >> n >> m;
	for(int i = 1; i <= n; ++i) cin >> a[i], b[i] = (a[i] != a[i-1]);

	int sm = 0;
	for(int i = 1; i <= n; ++i) 
		sm += b[i] * (n-i+1) * i;

	for(int j = 1; j <= m; ++j) {
		int i, x; cin >> i >> x;
		a[i] = x;
		int prev1 = b[i];
		b[i] = a[i] != a[i-1];

		if(b[i] != prev1)
			sm += (b[i] - prev1) * (n-i+1) * i;
		++i;

		if(i <= n) {
			int prev2 = b[i];
			b[i] = a[i] != a[i-1];

			if(b[i] != prev2)
				sm += (b[i] - prev2) * (n-i+1) * i;
		}
		cout << sm << '\n';
	}
}
