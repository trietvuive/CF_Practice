#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n; cin >> n;
	while (n--)
	{
		int a, b;
		cin >> a >> b;
		if ((a + b) % 2)
			printf("%d %d\n", -1, -1);
		else
			printf("%d %d\n", a / 2, b / 2 + a % 2);
	}
}