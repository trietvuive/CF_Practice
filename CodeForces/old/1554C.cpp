#include<bits/stdc++.h>
using namespace std;

int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		int n, m;
		cin >> n >> m;
		int r = 0;
		for (int i = 30; i >= 0; --i)
		{
			if ((r ^ n | ((1 << i) - 1)) <= m)
				r |= 1 << i;
		}
		cout << r << endl;
	}
}
