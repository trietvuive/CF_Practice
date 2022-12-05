#include<bits/stdc++.h>

using namespace std;

int main() {
	int t;
	cin >> t;
	while (t--)
	{
		int W, H, x1, y1, x2, y2, w, h;
		cin >> W >> H >> x1 >> y1 >> x2 >> y2 >> w >> h;
		if (x2 - x1 + w > W && y2 - y1 + h > H)
			cout << -1 << endl;
		else
		{
			int distance = 1e9;
			if (x2 - x1 + w <= W) distance = min(distance, w - max(W - x2, x1));
			if (y2 - y1 + h <= H) distance = min(distance, h - max(H - y2, y1));
			distance = max(distance, 0);
			cout << distance << endl;
		}
	}
}
