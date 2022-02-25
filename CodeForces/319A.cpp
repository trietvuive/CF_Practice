#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int MOD = 1e9 + 7;

ll four_pow(int power)
{
	if (!power) return 1;
	ll half_pow = four_pow(power / 2) % MOD;
	return half_pow * half_pow % MOD * (power % 2 ? 4 : 1) % MOD;
}

int main()
{
	string s; cin >> s;
	ll ans = s[s.size() - 1] == '1';
	for (int i = s.size() - 2; i >= 0; --i)
	{
		if (s[i] == '1') {
			ll combo = four_pow(s.size() - 1 - i);
			ans = (ans * 2 + combo) % MOD;
		}
		else
			ans = ans * 2 % MOD;
	}
	cout << ans << endl;
}