#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

const int MAX_N = 1e5 + 2;
int ar[MAX_N];

int main()
{
	int n, k, unique = 0, left = 0, right = -1;
	unordered_map<int, int> cnt;
	scanf("%d %d", &n, &k);
	for (int i = 0; i < n; ++i)
	{
		scanf("%d", ar+i);
		if (!cnt[ar[i]])++unique;
		if(right == -1)++cnt[ar[i]];
		if(unique == k && right == -1)right = i;
	}
	if (right == -1)
	{
		printf("%d %d\n", -1, -1);
		return 0;
	}
	while (cnt[ar[right]] > 1)--cnt[ar[right--]];
	while (cnt[ar[left]] > 1)--cnt[ar[left++]];
	printf("%d %d\n", left + 1, right + 1);
}