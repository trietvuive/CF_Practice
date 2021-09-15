#include<bits/stdc++.h>
using namespace std;

int main() {
	int tc; cin >> tc;
	while (tc-- > 0)
	{
		int n;
		string s;
		cin >> n >> s;
		for (int i = 1; i <= n; ++i)
			if (s[i-1] == '0' && i * 2 - 1 != n)
			{
				if (i * 2 - 1 < n) printf("%d %d %d %d\n", i, n, i + 1, n);
				else printf("%d %d %d %d \n", 1, i, 1, i - 1);
				goto end;
			}
		printf("%d %d %d %d\n", 1, (n + 1) / 2, n / 2 + 1, n);
	end:;
	}
}