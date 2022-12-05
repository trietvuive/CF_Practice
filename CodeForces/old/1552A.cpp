#include<bits/stdc++.h>
using namespace std;

int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		int n;
		cin >> n;
		string s;
		cin >> s;
		string original = s;

		sort(s.begin(), s.end());
		int ans = 0;
		for (int i = 0; i < n; ++i)
			if (original[i] != s[i])++ans;
		cout << ans << endl;
	}
}