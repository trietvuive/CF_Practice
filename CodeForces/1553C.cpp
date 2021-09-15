#include<bits/stdc++.h>
using namespace std;

int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		string s;
		cin >> s;
		int a = 0, b = 0, a1 = 0, b1 = 0, i = 0;
		for (i = 0; i < 10; ++i)
		{
			if (s[i] == '1') a += (i + 1) % 2, b += i % 2;
			if (s[i] == '?') a1 += (i + 1) % 2, b1 += i % 2;
			if (a + a1 > b + (10 - i) / 2 || b + b1 > a + (9 - i) / 2)
			{
				++i;
				break;
			}
		}
		cout << i << endl;
	}
}