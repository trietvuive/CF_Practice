#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n; cin >> n;
	while (n--)
	{
		string s; cin >> s;
		int idx = -1;
		for (int i = 0; i < s.size() - 1; ++i)
			if (s[i] - '0' + s[i + 1] - '0' >= 10)
				idx = i;
		if (idx != -1)
		{
			int num = s[idx] - '0' + s[idx + 1] - '0';
			s[idx] = '1', s[idx + 1] = num % 10 + '0';
		}
		else
		{
			s[1] = s[0] - '0' + s[1];
			s = s.substr(1);
		}
		cout << s << endl;
	}
}