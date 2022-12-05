#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int MOD = 1e9 + 7;
int main()
{
	int n; cin >> n;
	ll odd = 1, even = 0;
	for (int i = 2; i <= n; ++i)
	{
		if (i % 2) odd = (odd + even + 1) % MOD;
		else even = (even + odd + 1) % MOD;
	}
	cout << (odd + even) % MOD << endl;
}