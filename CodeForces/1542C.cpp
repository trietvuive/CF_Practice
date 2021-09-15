#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll MOD = 1e9 + 7;
ll gcd(ll a, ll b)
{
	if (b == 0)return a;
	return gcd(b, a % b);
}
ll lcm(ll a, ll b)
{
	return a / gcd(a, b) * b;
}
int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		ll n;
		cin >> n;
		ll sum = 0;
		ll divisible = 1;
		ll last_count = 0, current_count = 0;

		for (ll i = 2; divisible <= n; ++i)
		{
			divisible = lcm(divisible, i);
			current_count = n - n/divisible;
			sum = (sum + (current_count - last_count) * i) % MOD;
			last_count = current_count;
		}
		cout << sum << endl;
	}
}
