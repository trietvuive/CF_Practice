#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll getMax() {
	int n, mn, mx, element; cin >> n;
	cin >> mn; for (int i = 1; i < n - 1; ++i) cin >> element;
	cin >> mx;
	return mx - mn;
}
int main()
{
	int tc; cin >> tc;
	while (tc--) {
		ll mx = 0, w, h; cin >> w >> h;
		mx = max(mx, getMax() * h);
		mx = max(mx, getMax() * h);
		mx = max(mx, getMax() * w);
		mx = max(mx, getMax() * w);
		cout << mx << endl;
	}
}