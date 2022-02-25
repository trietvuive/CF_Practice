#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n; scanf("%d", &n);
	int right = 0, left = 0, x, y;
	for (int i = 0; i < n; ++i)
	{
		scanf("%d %d", &x, &y);
		right += x > 0, left += x < 0;
	}
	if (left <= 1 || right <= 1)
		cout << "YES\n";
	else cout << "NO\n";
}