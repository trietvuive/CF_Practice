#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n; cin >> n;
	while (n--)
	{
		int a, b, c, d, e, f, g;
		cin >> a >> b >> c >> d >> e >> f >> g;
		printf("%d %d %d\n", a, b, g - a - b);
	}
}