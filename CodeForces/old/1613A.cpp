#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n; cin >> n;
	while (n--)
	{
		int a1, p1, a2, p2; cin >> a1 >> p1 >> a2 >> p2;
		while (p1 != p2)
			if (p1 > p2)
				if (a1 > a2) break;
				else a1 *= 10, --p1;
			else if (p2 > p1)
				if (a2 > a1)break;
				else a2 *= 10, --p2;
		cout << (a1 > a2 ? ">" : a1 == a2 ? "=" : "<") << endl;
	}
}