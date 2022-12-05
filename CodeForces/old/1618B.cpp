#include<bits/stdc++.h>
using namespace std;

int main()
{
	int tc; cin >> tc;
	while (tc--)
	{
		int n; cin >> n;
		string ans; cin >> ans;
		for (int i = 1; i < n-2; ++i)
		{
			string nxt; cin >> nxt;
			if (nxt[0] == ans[ans.size() - 1])
				ans += nxt[1];
			else
				ans += nxt;
		}
		if (ans.size() != n)ans += 'a';
		cout << ans << endl;
	}
}