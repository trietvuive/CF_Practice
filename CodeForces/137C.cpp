#include<bits/stdc++.h>
using namespace std;

#define pii pair<int,int>
const int MAX = 1e5 + 2;
pii ar[MAX];

int main()
{
	int n; scanf("%d", &n);
	for (int i = 0; i < n; ++i)
	{
		int a, b; scanf("%d %d", &a, &b);
		ar[i] = { a,b };
	}
	sort(ar, ar + n);
	int max_right = ar[0].second, cnt = 0;
	for (int i = 1; i < n; ++i)
		cnt += ar[i].second < max_right, max_right = max(max_right, ar[i].second);
	cout << cnt << endl;
}