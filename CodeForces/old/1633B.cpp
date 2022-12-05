#include<bits/stdc++.h>
using namespace std;

int main()
{
	int tc; cin >> tc;
	for (int i = 0; i < tc; ++i)
	{
		string s; cin >> s;
		int one = 0, zero = 0;
		for (int i = 0; i < s.size(); ++i)
			one += s[i] == '1',
			zero += s[i] == '0';
		cout << (one == zero ? one - 1 : min(zero, one)) << endl;
	}
}