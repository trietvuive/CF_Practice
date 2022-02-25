#include<bits/stdc++.h>
using namespace std;

int main()
{
	int h, m; char c;
	cin >> h >> c >> m;
	h %= 12;
	double hd = h, md = m;
	cout << (hd * 30 + md / 2) << " " << md * 6 << endl;
}