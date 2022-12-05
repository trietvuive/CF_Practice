#include<bits/stdc++.h>
using namespace std;

int main()
{
	string s; cin >> s;
	string attempt;
	for (int trial = 0; trial < 7; ++trial) {
		set<char> all_chars, g_chars;
		cin >> attempt;
		string feedback = "#####";
		for (int i = 0; i < 5; ++i)
		{
			if (s[i] == attempt[i])
				feedback[i] = 'G', g_chars.insert(s[i]);
			all_chars.insert(s[i]);
		}

		for (char c : g_chars)
			all_chars.erase(c);

		for (int i = 0; i < 5; ++i)
		{
			if (feedback[i] != '#') continue;

			if (all_chars.count(attempt[i]))
				feedback[i] = 'Y';
			else feedback[i] = 'X';
		}

		if (feedback == "GGGGG") {
			cout << "WINNER\n";
			return 0;
		}
		else if (trial == 6)
			cout << "LOSER\n";
		else cout << feedback << endl;
	}
}