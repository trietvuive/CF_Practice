/*#include<bits/stdc++.h>
#include "bigint.h"
#define ll long long
const ll MOD = 432e11;
using namespace std;
ll modInverse(ll a, ll m);
bigint sec_hr_inverse(modInverse(719, MOD));
bigint min_hr_inverse(modInverse(11, MOD));

ll gcdExtended(ll a, ll b, ll* x, ll* y);

// Function to find modulo inverse of a
ll modInverse(ll a, ll m)
{
    ll x, y;
    ll g = gcdExtended(a, m, &x, &y);
    if (g != 1)
        return -1;
    else
    {
        // m is added to handle negative x
        ll res = (x % m + m) % m;
        return res;
    }
}

// Function for extended Euclidean Algorithm
ll gcdExtended(ll a, ll b, ll* x, ll* y)
{

    // Base Case
    if (a == 0)
    {
        *x = 0, * y = 1;
        return b;
    }

    // To store results of recursive call
    ll x1, y1;
    ll gcd = gcdExtended(b % a, a, &x1, &y1);

    // Update x and y using results of recursive
    // call
    *x = y1 - (b / a) * x1;
    *y = x1;

    return gcd;
}
bigint verify_nano(ll hour, ll minute, ll second)
{
    bigint min_hr((minute - hour) % MOD);
    bigint nano_1 = (min_hr * min_hr_inverse) % bigint(MOD);
    bigint sec_hr((second - hour) % MOD);
    bigint nano_2 = (sec_hr * sec_hr_inverse) % bigint(MOD);
    if (nano_1 == nano_2)
        return nano_1;
    return -1;
}
bigint check(ll a, ll b, ll c)
{
    bigint ans = verify_nano(a, b, c);
    if (ans != bigint(-1))return ans;
    ans = verify_nano(a, c, b);
    if (ans != bigint(-1))return ans;
    ans = verify_nano(b, a, c);
    if (ans != bigint(-1))return ans;
    ans = verify_nano(b, c, a);
    if (ans != bigint(-1))return ans;
    ans = verify_nano(c, b, a);
    if (ans != bigint(-1))return ans;
    ans = verify_nano(c, a, b);
    if (ans != bigint(-1))return ans;
    return -1;
}
int main()
{
    cout << bigint(modInverse(719, MOD)) << endl;
    cout << bigint(modInverse(-719, MOD)) << endl;
    cout << (719 * modInverse(719, MOD)) % MOD << endl;
    cout << -721 % 720 << endl;
    cout << (-719 * modInverse(719, MOD)) % MOD << endl;
	int cases;
	cin >> cases;
	for (int i = 1; i <= cases; ++i)
	{
		ll a1, a2, a3;
		cin >> a1 >> a2 >> a3;
        bigint nano = check(a1, a2, a3);
        bigint second = nano / bigint((ll)1e9);
        bigint minute = second / bigint(60);
        bigint hour = minute / bigint(60);
        cout << "Case #" << i << ": " << hour << " " << (minute % bigint(60)) << " " 
            << (second % bigint(60)) << " " << (bigint(nano) % bigint((ll)1e9)) << endl;
	}
}
*/