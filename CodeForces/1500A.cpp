/*
#include<vector>
#include<iostream>
#include<unordered_map>
#define MAXN 5000001
int N, v[MAXN], x[MAXN], y[MAXN];
using namespace std;

int main()
{
	int n;
	cin >> n;
	unordered_map<int, int> all_sums;
	for (int i = 1; i <= n; i++)
	{
		cin >> v[i];
	}
	for (int i = 1; i <= n; i++)
	{
		for (int j = i + 1; j <= n; j++)
		{
			int sum = v[i] + v[j];
			if (!x[sum]) {
				x[sum] = i;
				y[sum] = j;
			}
			else
			{
				if (i != x[sum] && j != y[sum] && i != y[sum] && j != x[sum]) {
					cout << "YES" << endl << i << " " << j << " " << x[sum] << " " << y[sum] << endl;
					return 0;
				}
			}
		}
	}
	cout << "NO" << endl;
}
*/
