#include<bits/stdc++.h>
using namespace std;
int n, graph[6][50002];
int win(int a, int b)
{
	int w = 0;
	for (int i = 1; i <= 5; ++i)w += graph[i][a] < graph[i][b];
	return w >= 3 ? a : b;
}
int main()
{
	int t; cin >> t;
	while (t--)
	{
		int n; cin >> n;
		for (int i = 1; i <= n; ++i)
			for (int j = 1; j <= 5; ++j)
				cin >> graph[j][i];
		int winner = 1;
		for (int i = 1; i <= n; ++i)
			winner = win(winner, i);
		for (int i = 1; i <= n; ++i)
			if (winner != win(winner, i)) {
				winner = -1;
				break;
			}
		cout << winner << endl;

	}
}