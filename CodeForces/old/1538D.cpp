#include<bits/stdc++.h>
using namespace std;
#define ll long long
int pf(int x)
{
	int ans = 0;
	for (int i = 2; i * i <= x; ++i)while (x % i == 0)++ans, x /= i;
	if (x > 1) ++ans;
	return ans;
}
int main()
{
	ios::sync_with_stdio(false);
	int t;
	cin >> t;
	while (t--)
	{
		int a, b, k;
		cin >> a >> b >> k;
		if (a > b)swap(a, b);
		int hi = pf(a) + pf(b);
		int lo = b % a == 0 && a != b ? 1 : 2;
		cout << (lo <= k && k <= hi ? "YES" : "NO") << endl;
	}
}
