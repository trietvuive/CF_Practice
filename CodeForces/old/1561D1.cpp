#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int MAX_N = 4e6 + 10;
ll dp[MAX_N];
int main()
{
	int n, mod;
	cin >> n >> mod;
	dp[1] = 1;
	for (int i = 2; i <= n; ++i)
	{
		//imagine a set (with repetition) of cell that you can reach from i and i+1
		//from i+1, you can reach every cell that i can reach by subtraction (division will have some exception)
		//you can also reach i itself
		//you also have an extra 1 that you can reach by dividing by i+1
		dp[i] = (dp[i] + 2 * dp[i - 1] + 1) % mod;
		if (i == 2)dp[i]--;//since dp[1] is the base case and dp[1] = 1 doesn't mean that you can reach any cell from 1 by subtraction
		for (int j = 2 * i; j <= n; j += i)
			//for each j where j divides i, you can reach i from j
			//however, you lost an i-1 that you can reach from j-1 (that you count by reaching everything j-1 reaches)
			dp[j] = (dp[j] + dp[i] - dp[i - 1] + mod) % mod;
	}
	cout << dp[n] << endl;
}
