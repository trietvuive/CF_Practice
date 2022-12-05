#include<bits/stdc++.h>
using namespace std;

string s, composite[17]{ "1","4","6","8","9","22","25","27","32","33","35","52","55","57","72","75","77" };

int main()
{
	int tc; cin >> tc;
	while (tc-- > 0)
	{
		int k;
		string s;
		cin >> k >> s;
		for (int i = 0; i < 17; ++i)
		{
			int ptr = 0;
			for (int j = 0; j < k; ++j)
				if (ptr < composite[i].size() && s[j] == composite[i][ptr])++ptr;
			if (ptr == composite[i].size()) {
				cout << ptr << endl << composite[i] << endl;
				break;
			}

		}
	}
}