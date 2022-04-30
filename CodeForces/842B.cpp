#include<bits/stdc++.h>
using namespace std;
int r, d, n, ans;
int main() {
	cin >> r >> d >> n;
	for (int i = 0; i < n; ++i)
	{
		int x, y, r0; cin >> x >> y >> r0;
		ans += 
			(r - d + r0) * (r - d + r0) <= x * x + y * y &&
			x * x + y * y <= (r - r0) * (r - r0);
	}
	cout << ans << endl;
}