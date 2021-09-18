#include<bits/stdc++.h>
using namespace std;

int main()
{
	int tc; 
	cout.sync_with_stdio(false);
	cin.sync_with_stdio(false);
	cin >> tc;
	while (tc-- > 0)
	{
		string s; 
		cin >> s;
		int left = 0, right = s.size() - 1;
		bool ans = true;
		for (char c = s.size() + 'a' - 1; c >= 'a'; --c)
		{
			if (s[left] == c)++left;
			else if (s[right] == c)--right;
			else
			{
				ans = false;
				break;
			}
		}
		if (ans) cout << "YES\n";
		else cout << "NO\n";
	}
}