#include<bits/stdc++.h>
using namespace std;
int main()
{
	int tc;
	cin >> tc;
	while (tc--)
	{
		string s; cin >> s;
		char mn = 'z';
		int mn_index = -1;
		for (int i = 0; i < s.size(); ++i)
			if (s[i] <= mn) mn = s[i], mn_index = i;
		cout << mn << ' ';
		for (int i = 0; i < s.size(); ++i)
			if (i != mn_index)cout << s[i];
		cout << endl;
	}
}