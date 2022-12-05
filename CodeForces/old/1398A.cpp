#include<bits/stdc++.h>
using namespace std;
int main()
{
	int tc; scanf("%d", &tc);
	while (tc--)
	{
		int n; scanf("%d", &n);
		int first, second, last, element;
		for (int i = 1; i <= n; ++i)
		{
			scanf("%d", &element);
			if (i == 1)first = element;
			if (i == 2)second = element;
			if (i == n) last = element;
		}
		if (first + second <= last)
			printf("1 2 %d\n", n);
		else
			printf("-1\n");
	}
}