#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll d[3], k, c[3];
int main()
{
	cin >> d[0] >> d[1] >> d[2] >> k;
	sort(d, d + 3);
	c[0] = min(d[0] - 1, k / 3);
	c[1] = min(d[1] - 1, (k - c[0]) / 2);
	c[2] = min(d[2] - 1, k - c[0] - c[1]);
	++c[0], ++c[1], ++c[2];
	cout << c[0] * c[1] * c[2] << endl;
}