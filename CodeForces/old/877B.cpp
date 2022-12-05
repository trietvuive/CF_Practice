#include<bits/stdc++.h>
using namespace std;

int main()
{
	string s;
	cin >> s;
	int first = 0, second = 0, third = 0;
	for (int i = 0; i < s.size(); ++i)
		if (s[i] == 'a')
			++first, third = max(third + 1, second + 1);
		else
			second = max(first + 1, second + 1);
	cout << max(first, max(second, third)) << endl;
}