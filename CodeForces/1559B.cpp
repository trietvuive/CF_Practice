#include<bits/stdc++.h>
using namespace std;
int n;
void dfs(string& s, int i)
{
	if (i < 0 || i >= n || s[i] != '?')return;
	if (i > 0 && s[i - 1] != '?')
	{
		if (s[i - 1] == 'R')s[i] = 'B';
		else s[i] = 'R';
		dfs(s, i + 1);
	}
	if (i < n - 1 && s[i + 1] != '?')
	{
		if (s[i + 1] == 'R')s[i] = 'B';
		else s[i] = 'R';
		dfs(s, i - 1);
	}
}
int main()
{
	int t;
	cin >> t;
	while (t--) {
		string s;
		cin >> n >> s;
		int min_imp = 0;
		for (int i = 0; i < n; ++i)
		{
			if (s[i] != '?')dfs(s, i - 1), dfs(s, i + 1);
		}
		if (s[0] == '?')s[0] = 'B', dfs(s, 1);
		cout << s << endl;
	}
}
