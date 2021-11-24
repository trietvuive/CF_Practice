#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
	int tc; cin >> tc;
	while (tc-- > 0)
	{
		ll x, n; cin >> x >> n;
		if(n >= 1)
			x += x % 2 ? 1 : -1, --n;
		x += (x % 2 ? -1 : 1) * 4 * (n / 4), ++n;
		for (ll i = (n / 4 - (n%4 == 0)) * 4 + 2; i <= n; ++i)
			x += (x % 2 ? 1 : -1) * i;
		cout << x << endl;

	}
}