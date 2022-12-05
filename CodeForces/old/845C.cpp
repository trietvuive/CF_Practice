#include<bits/stdc++.h>
using namespace std;
const int MAX_N = 2e5 + 2;
#define pii pair<int,int>
pii ar[MAX_N];
int main()
{
	int n; cin >> n;
	for (int i = 0; i < n; ++i)
		scanf("%d %d", &ar[i].first, &ar[i].second);
	sort(ar, ar + n, [](const pii& a, const pii& b)
		{
			return a.first < b.first;
		});
	priority_queue<int, vector<int>, greater<int>> min_heap;
	for (int i = 0; i < n; ++i)
	{
		while (min_heap.size() > 0 && min_heap.top() < ar[i].first)
			min_heap.pop();
		min_heap.push(ar[i].second);
		if (min_heap.size() > 2)
		{
			printf("NO\n");
			return 0;
		}
	}
	printf("YES\n");
}