#include<bits/stdc++.h>
#include <unordered_map>
using namespace std;
const int MAX_N = 1e6 + 20;
int cnt[MAX_N];
int main()
{
	int n, max_element = 0, ans = 0;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i)
	{
		int element; scanf("%d", &element);
		++cnt[element];
		max_element = max(max_element, element);
	}
	for (int i = 0; i <= max_element + 1 || cnt[i]; ++i)
	{
		ans += cnt[i] % 2;
		int count = cnt[i], idx = 0;
		while (count > 0)
		{
			if (count % 2) ++cnt[i + idx];
			++idx, count /= 2;
		}
	}
	cout << ans << endl;
}