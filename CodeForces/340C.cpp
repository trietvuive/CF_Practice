#include<bits/stdc++.h>
#include<algorithm>

using namespace std;
#define ll long long
ll i, n, ans = 0LL, s[100001];
//Each element can be the first position. There are (n-1)! permutations of it. Hence, sum = sum of all elements / n;
//Any two elements can be in consecutive position. There are (n-2)! permutation of it, along with n-1 different consecutive positions.
//Hence, sum = abs difference of any two elements / n
//Hence, total sum = sum of all elements + sum difference of any two elements / n

//For the second part, instead of iterating n^2, we can do better
// The sum of the second part = 2 * sum of (element - lesser element). Multiply by 2 since |element - lesser element| = |lesser element - element|
// Then, let's sort the array. Element at position i will have i elements to the left (lesser) and n - 1 - i elements to the right (larger).
// Then, the element at position i will appears with a plus sign i times and negative sign n - 1 - i times.
// Then, sum = element at i * (i - (n - 1 - i)) = element at i * (2*i - n + 1). Multiply by 2 bcuz |element - lesser| = |lesser - element|
// + 1 for the first sum.

ll gcd(ll a, ll b)
{
	if (a == 0)return b;
	return gcd(b % a, a);
}
int main()
{
	cin >> n;
	for (i = 0; i < n; ++i)cin >> s[i];
	sort(s, s + n);
	for (i = 0; i < n; ++i)
		ans += s[i] * (1 + (2 * i - n + 1) * 2);
	ll div = gcd(ans, n);
	cout << ans / div << " " << n / div;

}