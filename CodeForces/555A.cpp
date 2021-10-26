#include<bits/stdc++.h>

using namespace std;

const int MAX_N = 1e5 + 2;
int chain_loc[MAX_N], chain_size[MAX_N];

int main()
{
	int n, k; scanf("%d %d", &n, &k);
	for (int i = 0; i < k; ++i)
	{
		scanf("%d", chain_size + i);
		for (int j = 0; j < chain_size[i]; ++j)
		{
			int element;
			scanf("%d", &element);
			chain_loc[element] = i;
		}
	}
	int last_chain = chain_loc[1];
	--chain_size[last_chain];
	int ans = 0;
	for (int i = 2; i <= n; ++i)
		if (last_chain != chain_loc[i])
			 ++ans, ans += chain_size[last_chain] > 0, 
			last_chain = chain_loc[i], --chain_size[last_chain];
		else --chain_size[last_chain];
	cout << ans << endl;
}