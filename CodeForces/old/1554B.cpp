#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int MAX = 1e5 + 2;
int a[MAX];
int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		int n, k;
		cin >> n >> k;
		for (int i = 1; i <= n; ++i)
			cin >> a[i];
		ll ans = INT_MIN;
		for (ll i = n; i >= 1 && i*(i-1) > ans; --i)
			for (ll j = i-1; j >= 1 && i*j > ans; --j)
				ans = max(ans, i * j - k * (a[i] | a[j]));
		cout << ans << endl;
	}
}
