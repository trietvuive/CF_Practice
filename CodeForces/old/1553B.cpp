#include<bits/stdc++.h>
using namespace std;

bool zigzag(const string& s, const string& t)
{
	for (int i = 0; i < s.size(); ++i)
	{
		int pointer_s = i, pointer_t = 0;
		while (pointer_s < s.size() && pointer_t < t.size() && s[pointer_s] == t[pointer_t])
		{
			int rev_s = pointer_s - 1, rev_t = pointer_t + 1;
			for (; rev_s >= 0 && rev_t < t.size() && s[rev_s] == t[rev_t]; --rev_s, ++rev_t);
			if (rev_t == t.size())return true;
			++pointer_s, ++pointer_t;
		}
		if (pointer_t == t.size())return true;
	}
	return false;
}
int main() {
	int t;
	cin >> t;
	while (t--)
	{
		string s, t;
		cin >> s >> t;
		if (zigzag(s, t))
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}
}