#include<bits/stdc++.h>
using namespace std;
int n, a, b, i, j, k;
int main()
{
	scanf("%d %d %d", &n, &a, &b);
	for (int i = 0; i <= n; ++i)
	{
		if (i % a == 0 && (n - i) % b == 0)
		{
			for (j = 1; j <= i; j += a)
				for (k = 1; k <= a; ++k)
					printf("%d ", j + k % a);
			for (j = i + 1; j <= n; j += b)
				for (k = 1; k <= b; ++k)
					printf("%d ", j + k % b);
			return 0;
		}
	}
	puts("-1");
}