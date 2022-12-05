#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n, m, x; cin >> m >> n >> x;
	n -= 2*(x - 1), m -= 2*(x - 1);

	int ans = 0;
	int x1 = 1, y1 = 1; //top left side
	int x2 = 1, y2 = (m-y1) % 2 ? m - 1 : m; //bottom left side

	int x3 = y2 == m ? 1 : 2, y3 = m; //left bottom
	int x4 = (n - x3) % 2 ? n - 1 : n, y4 = y3; //right bottom

	int x5 = n, y5 = (n - 1) % 2 ? 2 : 1; //top right
	int x6 = x5, y6 = (m - y5) % 2 ? m - 1 : m; //bottom right

	int x7 = (n - x1) % 2 ? n - 1 : n, y7 = y1; // right top

	ans += max(0,(y2 - y1) / 2 + 1); //left side
	ans += max(0,(x4 - x3) / 2 + 1 - (x2 == x3)); //bottom side
	ans += max(0,(y6 - y5) / 2 + 1 - (x4 == x6)); //right side
	ans += max(0,(x7 - x1) / 2 - (x7 == x5)); //top side
	if (n < 1 || m < 1)
		cout << 0 << endl;
	else cout << ans << endl;

}