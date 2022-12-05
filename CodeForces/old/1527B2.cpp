#include<bits/stdc++.h>
using namespace std;

int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		int n, zero = 0, flag = 0;
		cin >> n;
		string s;
		cin >> s;
		for (int i = 0; i < s.size(); ++i)
			flag |= (s[i] != s[n-i-1]), zero += (s[i] == '0');
		if (flag == 0)
			cout << (zero % 2 && zero != 1 ? "ALICE" : "BOB") << endl;
		else
			cout << (n % 2 && zero == 2 && s[n / 2] == '0' ? "DRAW" : "ALICE") << endl;
	}
}