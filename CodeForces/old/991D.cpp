#include<bits/stdc++.h>
using namespace std;
char a[102], b[102];
int main()
{
	scanf("%s", a);
	scanf("%s", b);
	int cnt = 0, accum = 0;
	for (int i = 0; a[i] != 0; ++i)
	{
		int avail = (a[i] == '0') + (b[i] == '0');
		accum += avail;
		if (accum >= 3)
			++cnt, accum -= 3;
		else
			accum = avail;
	}
	printf("%d", cnt);
}