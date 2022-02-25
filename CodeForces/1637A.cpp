#include<bits/stdc++.h>
using namespace std;
int main()
{
	int tc; scanf("%d", &tc);
	while (tc--)
	{
		int n; scanf("%d", &n);
		bool sorted = true;
		int last = -1e9, element;
		for (int i = 0; i < n; ++i)
		{
			scanf("%d", &element);
			sorted &= element >= last, last = element;
		}
		if (sorted) cout << "NO\n";
		else cout << "YES\n";
	}
}