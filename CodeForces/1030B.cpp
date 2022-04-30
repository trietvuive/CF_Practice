#include<bits/stdc++.h>
using namespace std;

int side(int x0, int y0, int px, int py, int sign)
{
	int yhigh = y0 + (px - x0), ylow = y0 - (px - x0);
	return sign*(py-yhigh) >= 0 && sign*(py-ylow) >= 0;
}

int main()
{
	int n, d, m; cin >> n >> d >> m;
	for (int i = 0; i < m; ++i)
	{
		int px, py; cin >> px >> py;
		if (side(d,0,px,py,1) &&
			side(n-d,n,px,py,-1))
			cout << "YES\n";
		else
			cout << "NO\n";
	}
}