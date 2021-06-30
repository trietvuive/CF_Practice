/*#include<iostream>
#include<vector>

const double NEG_INFINITY = -1e300;
const int MAX = 10e5 + 2;
double dp[MAX][10];
int pre[MAX][10], ar[MAX];

using namespace std;
int main()
{
	int n, d;
	cin >> n >> d;
	for (int i = 0; i <= n; i++)
		for (int j = 0; j < 10; j++)
			pre[i][j] = -1;
	for (int i = 0; i <= n; i++)
		for (int j = 0; j < 10; j++)
			dp[i][j] = NEG_INFINITY;
	//start out at 1 so 1 is good
	dp[0][1] = 0;

	for (int i = 1; i <= n; i++)
	{
		for (int j = 0; j < 10; j++)
			dp[i][j] = dp[i - 1][j];
		cin >> ar[i];
		for (int j = 0; j < 10; j++)
		{
			int k = j * ar[i] % 10;
			if (dp[i][k] < dp[i - 1][j] + log(ar[i]))
			{
				dp[i][k] = dp[i - 1][j] + log(ar[i]);
				pre[i][k] = j;
			}
		}
	}
	vector<int>ans;
	while (n)
	{
		if (pre[n][d] != -1)
			ans.push_back(ar[n]), d = pre[n][d];
		n--;
	}
	if (ans.size() == 0)
		cout << -1 << endl;
	else
	{
		cout << ans.size() << endl;
		for (int i : ans)
			cout << i << " ";
		cout << endl;
	}
}*/