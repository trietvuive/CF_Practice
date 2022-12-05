#include<bits/stdc++.h>
#include<unordered_map>
using namespace std;

int main()
{
	unordered_map<int, int> cnt;
	int n; scanf("%d", &n);
	char c; scanf("%c", &c);
	int cum_sum = 0, ans = 0;
	for (int i = 1; i <= n; ++i) {
	    scanf("%c", &c);
		cum_sum += c == '1' ? 1 : -1;
		if (cnt[cum_sum] || cum_sum == 0)
			ans = max(ans, i - cnt[cum_sum]);
		else
			cnt[cum_sum] = i;
	}
	printf("%d\n",ans);
}