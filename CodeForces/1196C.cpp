#include<bits/stdc++.h>
using namespace std;
const int MAX_N = 1e5;
int lx, rx, by, uy, n, x, y, a, b, c, d, tc;
int main()
{
	scanf("%d", &tc);
	while (tc-- > 0)
	{
		lx = by = -MAX_N;
		rx = uy = MAX_N;
		scanf("%d", &n);
		while (n--)
		{
			scanf("%d %d %d %d %d %d", &x, &y, &a, &b, &c, &d);
			if (!a && lx < x)lx = x;
			if (!b && y < uy)uy = y;
			if (!c && x < rx)rx = x;
			if (!d && by < y)by = y;
		}
		if (lx <= rx && by <= uy)printf("1 %d %d\n", lx, by);
		else printf("0\n");
	}
}