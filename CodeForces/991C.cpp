#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll get_candies(ll n, ll k)
{
	ll ans = 0;
	while (n > 0)
		ans += min(n,k), n -= k, n -= n / 10;
	return ans;
}
int main() {
	ll n;
	cin >> n;
	ll left = 1, right = n / 10;
	while (left < right)
	{
		ll k = left + (right - left) / 2;
		ll candies = get_candies(n, k);
		if (candies >= (n + 1) / 2)
			right = k;
		else
			left = k + 1;
	}
	cout << left << endl;
}