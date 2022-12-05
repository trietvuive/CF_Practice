#include<bits/stdc++.h>

using namespace std;
int main()
{
	int n;
	cin >> n;
	string s;
	cin >> s;
	int zero_balance = n / 3, one_balance = n / 3, two_balance = n / 3;
	for (int i = 0; i < n; ++i)
		if (s[i] == '0')--zero_balance;
		else if (s[i] == '1')--one_balance;
		else --two_balance;
	int zero_seen = 0, one_seen = 0;
	for (int i = 0; i < n; ++i)
	{
		if (s[i] == '0' && zero_balance < 0)
		{
			if (zero_seen == n / 3)
				if (one_balance > 0)s[i] = '1', --one_balance, ++zero_balance;
				else s[i] = '2', --two_balance, ++zero_balance;
			else ++zero_seen;
		}
		else if (s[i] == '1' && one_balance < 0)
		{
			if (zero_balance > 0)s[i] = '0', --zero_balance, ++one_balance;
			else if (one_seen == n / 3) s[i] = '2', --two_balance, ++one_balance;
			else ++one_seen;
		}
		else if (s[i] == '2' && two_balance < 0)
		{
			if (zero_balance > 0)s[i] = '0', --zero_balance, ++two_balance;
			else if (one_balance > 0) s[i] = '1', --one_balance, ++two_balance;
		}
	}
	cout << s << endl;


}