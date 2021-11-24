#include<bits/stdc++.h>
using namespace std;
const int MAX_RANGE = 1 << 20;
int ar[MAX_RANGE], vis[MAX_RANGE];
int main()
{
	int n, cnt = 0;
	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		cin >> ar[i];
		int a = ar[i], b = 0;
		cnt += vis[a] == 0, vis[a] = 1;
		for (int j = i-1; j >= 0 && (a & ~b); --j)
			b |= ar[j], cnt += vis[a | b] == 0, vis[a | b] = 1;
	}
	cout << cnt << endl;
}