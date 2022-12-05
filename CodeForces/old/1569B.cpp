#include<bits/stdc++.h>
using namespace std;
int winner[52];
int main()
{
	int tc; cin >> tc;
	while (tc --> 0)
	{
		int n, n_winner = 0; cin >> n;
		string s; cin >> s;
		for (int i = 0; i < n; ++i)
			if (s[i] == '2')
				winner[n_winner++] = i;
		if (n_winner == 1 || n_winner == 2)
		{
			cout << "NO" << endl;
			continue;
		}
		else
		{
			cout << "YES" << endl;
			int ptr = 0;
			for (int i = 0; i < n; ++i)
			{
				if (s[i] == '2')
				{
					int opp_win = winner[(ptr + 1) % n_winner], opp_lose = winner[(ptr - 1 + n_winner) % n_winner];
					string res = string(n,'=');
					res[opp_win] = '+', res[opp_lose] = '-', res[i] = 'X';
					cout << res << endl;
					++ptr;
				}
				else
				{
					string res = string(n, '=');
					res[i] = 'X';
					cout << res << endl;
				}
			}
		}
	}
}