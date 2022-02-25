#include<bits/stdc++.h>
using namespace std;

bool even_digit(const string& s)
{
	for (int i = 0; i < s.size(); ++i)
		if ((s[i] - '0') % 2 == 0)
			return true;
	return false;
}

int main()
{
	int tc; cin >> tc;
	while (tc--)
	{
		string s; cin >> s;
		if ((s[s.size() - 1] - '0') % 2 == 0)
			cout << 0 << endl;
		else if ((s[0] - '0') % 2 == 0)
			cout << 1 << endl;
		else if (even_digit(s))
			cout << 2 << endl;
		else
			cout << -1 << endl;

	}
}