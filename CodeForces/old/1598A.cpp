#include<bits/stdc++.h>
using namespace std;


int main()
{
	int tc; cin >> tc;
	while (tc-- > 0)
	{
		int c; cin >> c;
		string a, b; cin >> a >> b;
		bool flag = false;
		for (int i = 0; i < c; ++i)
			if (a[i] == '1' && b[i] == '1')
				flag = true;
		if (flag) cout << "NO\n";
		else cout << "YES\n";
	}
}