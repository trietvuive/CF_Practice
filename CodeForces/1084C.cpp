#include<bits/stdc++.h>
using namespace std;

#define ll long long
const int MOD = 1e9 + 7;
const int MAX = 1e5 + 2;
char s[MAX];
int main()
{
	scanf("%s", s);
	int ans = 0, before_b = 0;
	bool b = false;
	for (int i = 0; s[i] != 0; ++i)
	{
		if (s[i] == 'b') b = true, before_b = ans;
		if (s[i] == 'a')
			ans = (ans + before_b + 1) % MOD, b = false;
	}
	printf("%d", ans);
}