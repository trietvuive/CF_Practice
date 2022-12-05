#include<bits/stdc++.h>
using namespace std;
int n, x, graph[1002], tail[1002], sm[1002] = { 1 };

int main()
{
	scanf("%d %d", &n, &x);
	for (int i = 1; i <= n; ++i)
		scanf("%d", graph + i), ++tail[graph[i]];

	int xpos = 0;
	for (int i = 1; i <= n; ++i)
	{
		if (!tail[i])
		{
			int com_sz = 0, x_seen = 0;
			for (int leader = i; leader > 0; leader = graph[leader], ++com_sz)
				if (x_seen |= (leader == x)) ++xpos;
			if (!x_seen)
				for (int j = n; j >= com_sz; --j) sm[j] |= sm[j - com_sz];
		}
	}

	for (int i = 0; i < n; ++i)
		if (sm[i])
			printf("%d\n", i + xpos);
}