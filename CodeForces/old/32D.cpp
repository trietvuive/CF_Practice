#include<bits/stdc++.h>
using namespace std;
const int MAX = 302;
string s[MAX];
int main()
{
	int n, m, k; cin >> n >> m >> k;
	for (int i = 0; i < n; ++i)
		cin >> s[i];
	vector<int> stars;
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			if (s[i][j] != '*')continue;
			int x = 1;
			for (int x = 1; i - x >= 0 && i + x < n && j - x >= 0 && j + x < m; ++x)
				if (s[i - x][j] == '*' && s[i + x][j] == '*' &&
					s[i][j - x] == '*' && s[i][j + x] == '*')
					stars.push_back(x * MAX * MAX + (i+1) * MAX + (j+1));
		}
	}
	sort(stars.begin(), stars.end());
	if (k > stars.size())
		cout << -1 << endl;
	else
	{
		int star = stars[k - 1];
		int size = star / (MAX * MAX),
			x = star % (MAX * MAX) / (MAX),
			y = star % MAX;
		printf("%d %d\n", x, y);
		printf("%d %d\n", x - size, y);
		printf("%d %d\n", x + size, y);
		printf("%d %d\n", x, y - size);
		printf("%d %d\n", x, y + size);

	}
}