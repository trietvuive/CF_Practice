#include<bits/stdc++.h>
using namespace std;

int main()
{
	int tc;
	cin >> tc;
	while (tc-- > 0)
	{
		int n; cin >> n;
		string s; cin >> s;
		for(int i = 0;i<n-1;++i)
			if (s[i] != s[i + 1])
			{
				cout << i + 1 << " " << i + 2 << endl;
				goto h;
			}
		cout << -1 << " " << -1 << endl;
	h:;
	continue;

	}

}