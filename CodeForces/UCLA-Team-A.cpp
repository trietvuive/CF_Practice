/*#include<bits/stdc++.h>
using namespace std;
bool is_vowel(char c)
{
	return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
}
int main()
{
	int n;
	cin >> n;
	string ans;
	for (int i = 0; i < n; ++i)
	{
		string s, temp1, temp2;
		cin >> s;
		char last_char = '#';
		for (int i = 0; i < s.size(); ++i)
		{
			if (s[i] == last_char)continue;
			else temp1 += s[i], last_char = s[i];
		}
		for (int i = 0; i < temp1.size(); ++i)
		{
			if ((i != 0 && i != temp1.size() - 1) && is_vowel(temp1[i]))continue;
			else temp2 += temp1[i];
		}
		ans += temp2;
		if (i != n)ans += ' ';
	}
	cout << ans << endl;
}
*/