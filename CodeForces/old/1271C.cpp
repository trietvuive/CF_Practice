#include<bits/stdc++.h>
using namespace std;
int n, sx, sy, q1, q2, q3, q4, x, y;
int main() {
	cin >> n >> sx >> sy;
	for (int i = 0; i < n; ++i) {
		cin >> x >> y;
		if (y > sy) ++q1;
		if (y < sy) ++q2;
		if (x > sx) ++q3;
		if (x < sx) ++q4;
	}
	int mx = max(max(q1, q2), max(q3, q4));
	cout << mx << endl;
	if (mx == q1)
		printf("%d %d\n", sx, sy + 1);
	else if(mx == q2)
		printf("%d %d\n", sx, sy - 1);
	else if (mx == q3)
		printf("%d %d\n", sx + 1, sy);
	else if (mx == q4)
		printf("%d %d\n", sx - 1, sy);
}