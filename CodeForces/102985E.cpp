/*#include<vector>
#include<iostream>
#include<algorithm>
#define ll long long
const int MAX = (5*10e6)+2;
int prime[MAX];
using namespace std;
int root(ll& a, ll b)
{
	if (a % b != 0)
		return 0;
	int res = root(a, b * b);
	if (a % b == 0)
	{
		a /= b;
		return res * 2 + 1;
	}
	return res * 2;
}
int main()
{
	int limit = 1;
	int cases;
	cin >> cases;
	for(int i = 0; i<cases;i++)
	{
		int a, b;
		cin >> a >> b;
		int count = 0;
		for (int i = 2; i <= a; i++)
		{
			if (i > limit)
			{
				if (!prime[i])
				{
					for (int j = 1; i * j <= MAX-2; j++)
					{
						ll temp = i * j;
						prime[i * j] += root(temp, i);
					}
				}
				limit = i;
			}
			if (i > b)
				count += prime[i];
		}
		cout << count << endl;
	}
}
*/