#include<bits/stdc++.h>
using namespace std;

int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		int n;
		cin >> n;
		int ans = -1;
		for (int i = 1; i <= 10; ++i)
		{
			if (7 * i % 10 == n % 10 && 7*i <= n)
				ans = i;
		}
		cout << ans << endl;
	}
}