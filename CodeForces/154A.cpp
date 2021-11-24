#include<bits/stdc++.h>

using namespace std;

int main()
{
	string s; int m; char a, b;
	int ret = 0, l, r;
	for (cin >> s >> m, s += '#'; m--;)
	{
		l = 0, r = 0;
		cin >> a >> b;
		for (int i = 0; i <= s.size(); ++i)
			if (s[i] == a)++l;
			else if (s[i] == b)++r;
			else ret += min(l, r), l = 0, r = 0;
	}
	cout << ret << endl;
}