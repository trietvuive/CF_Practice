#include<bits/stdc++.h>
using namespace std;

int main()
{
	cout.precision(17);
	int n, m, h, sh;
	cin >> n >> m >> h;
	double total = 0, non_dep = 0;
	for (int i = 1; i <= m; ++i)
	{
		cin >> sh;
		total += sh;
		if (i != h)
		non_dep += sh;
	}
	--total, --n;
	if (total < n)
	{
		cout << -1;
		return 0;
	}
	double odd = 1;
	while (n && non_dep >= 0)
	{
		odd *= non_dep-- / total--;
		--n;
	}
	cout << 1 - odd << endl;

}