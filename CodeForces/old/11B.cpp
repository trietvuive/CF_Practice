#include<bits/stdc++.h>
using namespace std;

int main()
{
	int x; cin >> x;
	x = abs(x);
	int a = sqrt(x*2), sum = a * (a + 1) / 2;
	while ((sum - x) % 2 || x > sum)
		++a, sum += a;
	cout << a << endl;
}