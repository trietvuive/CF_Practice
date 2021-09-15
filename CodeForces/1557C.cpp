#include<iostream>
using namespace std;
#define ll long long
ll MOD = 1e9 + 7;
ll pow(ll a, ll b)
{
	ll res = 1;
	while (b)
	{
		if (b & 1)res = (res * a) % MOD;
		b >>= 1;
		a = (a * a) % MOD;
	}
	return res;
}
int main()
{
	int tc;
	cin >> tc;
	while (tc-- > 0)
	{
		ll n, k; cin >> n >> k;
		ll c2 = pow(2, n - 1);
		//if N is odd, you can't do any better than all 1 (AND = 1 and XOR = 1) or choosing an even number of 1 (AND = 0, XOR = 0). There will be no cases where 
		//you have larger sig bit.
		//(n choose 0) + (n choose 2) + (n choose 4) +... (n choose n-(n%2)) == 2^(n-1). Then you pow this with k bits.
		if (n & 1) cout << pow((c2 + 1) % MOD, k) << endl;

		else cout << ((2*pow(2 *c2, k) + 2*c2*pow(c2 - 1, k)) % MOD * pow(2*c2+2, MOD - 2)) % MOD << endl;
	}
}
