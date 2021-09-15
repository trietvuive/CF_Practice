#include<bits/stdc++.h>
using namespace std;

int main()
{
	int t; cin >> t;
	while (t--)
	{
		string s, t, check, first;
		int n = 0;
		vector<int> cnt(27);
		cin >> s;
		reverse(s.begin(), s.end());
		for (int i = 0; i < s.size(); ++i)
		{
			if (!cnt[s[i] - 'a'])t += s[i];
			++cnt[s[i] - 'a'];
		}
		reverse(t.begin(), t.end());
		for (int i = 0; i < t.size(); ++i)
			n += cnt[t[i] - 'a'] / (i + 1);
		reverse(s.begin(), s.end());
		first = s.substr(0, n);
		for (char c : t)
		{
			check += first;
			first.erase(remove(first.begin(), first.end(), c), first.end());
		}
		if (check == s)
			cout << s.substr(0, n) << " " << t << endl;
		else
			cout << -1 << endl;
	}
}