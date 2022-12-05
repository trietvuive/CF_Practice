#include<bits/stdc++.h>
using namespace std;
const int MAX = 2e4 + 2;
int dp[MAX], n, cnt;
int gcd(int a, int b)
{
	if (!b)return a;
	return gcd(b, a % b);
}
int solve()
{
	if (cnt)return n - cnt;
	//gcd(a,gcd(b,c)) = gcd(gcd(a,b), gcd(b,c))
	//Note that gcd decreases number of factors and never increase
	//Set Theory: A AND (B AND C) = (A AND B) AND (B AND C) where AND is equivalent to having same factors
	for (int i = 1; i < n; ++i)
		for (int j = 0; i + j < n; ++j)
			if ((dp[j] = gcd(dp[j], dp[j + 1])) == 1)
				return i + n - 1;
	return -1;
}
int main()
{
	cin >> n;
	for (int i = 0; i < n; ++i)
		cin >> dp[i], cnt += dp[i] == 1;
	printf("%d\n", solve());
}