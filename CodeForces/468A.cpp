#include<cstdio>
using namespace std;

int main()
{
	int n; scanf("%d", &n);
	if (n < 4)printf("NO\n");
	else
	{
		printf("YES\n");
		if (n & 1)
			printf("5 * 4 = 20\n2 - 1 = 1\n1 + 3 = 4\n20 + 4 = 24\n");
		else
			printf("4 * 3 = 12\n12 * 2 = 24\n24 * 1 = 24\n");
		for (int i = 6 + (n & 1); i <= n; i += 2)
			printf("%d - %d = 1\n24 * 1 = 24\n", i, i - 1);
	}
}