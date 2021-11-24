#include<bits/stdc++.h>
using namespace std;
int alphabet[26];
char c;
int main()
{
	int tc; cin >> tc;
	while (tc --> 0)
	{
		for (int i = 0; i < 26; ++i)
			cin >> c, alphabet[c - 'a'] = i;
		string s; cin >> s;
		int ans = 0;
		for (int i = 1; i < s.size(); ++i)
			ans += abs(alphabet[s[i] - 'a'] - alphabet[s[i - 1] - 'a']);
		cout << ans << endl;
	}
}