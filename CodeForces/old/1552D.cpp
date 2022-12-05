#include<bits/stdc++.h>
using namespace std;
int a[15], n;
bool dfs(int k, int sum, int c)
{
	return k>=n ? (c>0 && sum == 0) : dfs(k+1,sum,c) || dfs(k + 1, sum + a[k], c+1) || dfs(k + 1, sum - a[k], c+1);
}
int main() {
	int t;
	cin >> t;
	while (t--)
	{
		cin >> n;
		for (int i = 0; i < n; ++i)cin >> a[i];
		cout << (dfs(0, 0,0) ? "YES" : "NO") << endl;
	}
}
