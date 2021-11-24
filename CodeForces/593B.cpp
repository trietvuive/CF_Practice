#include<bits/stdc++.h>
using namespace std;
#define pll pair<ll,ll>
#define ll long long
const int MAX_N = 1e6 + 2;
pll ar[MAX_N];
int main()
{
	ll n, x1, x2;
	cin >> n >> x1 >> x2;
	for (int i = 0; i < n; ++i)
	{
		ll k, b; cin >> k >> b;
		ar[i] = make_pair(k * x1 + b, k * x2 + b);
	}
	sort(ar, ar + n);
	for (int i = 1; i < n; ++i)
	{
		if (ar[i].second < ar[i - 1].second)
		{
			cout << "YES\n";
			return 0;
		}
	}
	cout << "NO\n";
	
}