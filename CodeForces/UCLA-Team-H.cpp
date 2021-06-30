/*#include<bits/stdc++.h>
using namespace std;
int dp[5001][5001];
bool play(int stone, int turn)
{
	if (dp[stone][turn])return dp[stone][turn] == 2;
	if (stone <= turn)
	{
		dp[stone][turn] = 1;
		return true;
	}
	if (stone <= turn + 2)
	{
		dp[stone][turn] = 1;
		return false;
	}
	if (stone <= turn + turn + 1 && stone > turn + 2)
	{
		dp[stone][turn] = 2;
		return true;
	}
	dp[stone][turn] = 1;
	for (int i = turn; i >= 1; --i)
		if (!play(stone - i, turn + 1))
		{
			dp[stone][turn] = 2;
			return true;
		}
	return false;
}
int main()
{
	int n;
	cin >> n;
	if (play(n, 1))
		cout << "YES" << endl;
	else
		cout << "NO" << endl;
}
*/