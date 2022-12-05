#include<bits/stdc++.h>
using namespace std;
int main() {
	int tc; cin >> tc;
	while (tc --> 0)
	{
		int n, a, b; cin >> n >> a >> b;
		string s;
		cin >> s;
		int zero_count = 0, one_count = 0;
		char c = '#';
		for(int i = 0;i<n;++i)
		{
			c = s[i];
			while (i+1 < n && s[i+1] == c)++i;
			if (c == '0')++zero_count;
			else ++one_count;
		}
		if (b >= 0)cout << (a + b) * n << endl;
		else
			cout << a * n + (min(zero_count, one_count) + 1) * b << endl;
	}
}