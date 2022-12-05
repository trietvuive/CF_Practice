#include<bits/stdc++.h>
using namespace std;
#define pii pair<int,int>
pii points[3];
int main() {
	for (int i = 0; i < 3; ++i)
		cin >> points[i].first >> points[i].second;
	sort(points, points + 3);
	pii a = points[0], b = points[1], c = points[2];
	// straight line
	if ((b.second - a.second) * (c.first - a.first) ==
		(c.second - a.second) * (b.first - a.first))
		cout << 0 << endl;
	else {
		cout << 3 << endl;
		printf("%d %d\n", a.first + c.first - b.first, a.second + c.second - b.second);
		printf("%d %d\n", a.first - c.first + b.first, a.second - c.second + b.second);
		printf("%d %d\n", c.first + b.first - a.first, c.second + b.second - a.second);

	}
}