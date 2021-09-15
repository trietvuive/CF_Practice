#include<iostream>
using namespace std;
const int MAX = 2e3 + 3;
int a[MAX];
int b[MAX];
int n;
int main()
{
	cin >> n;
	n <<= 1;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	int ans = n;
	for (int C = 0; C < 2; C++)
	{
		for (int j = 1; j <= n; j++)
			b[j] = a[j];
		int alternate = 0;
		for (int i = 0; i < n; i++)
		{
			int sorted = 1;
			for (int j = 1; j <= n; j++)sorted &= b[j] == j;
			if (sorted)ans = min(ans, i);
			if (alternate ^ C)
				for (int j = 1; j <= n; j += 2)
					swap(b[j], b[j + 1]);

			else
				for (int j = 1; j <= n / 2; j++)
					swap(b[j], b[n / 2 + j]);
			alternate ^= 1;
		}
	}
	if (ans == n)cout << -1 << endl;
	else cout << ans << endl;
}
