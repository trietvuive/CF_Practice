#include<bits/stdc++.h>
using namespace std;

int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		string s;
		cin >> s;
		vector<int> count(26, 0);
		int wasted = 0;
		for (char c : s)
			++count[c - 'a'], wasted += (count[c - 'a'] > 2 ? 1 : 0);
		cout << (s.size() - wasted) / 2 << endl;
	}
}
