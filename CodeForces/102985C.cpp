/*#include<iostream>
using namespace std;

int gcd(int a, int b)
{
	if (a == 0)
		return b;
	return gcd(b % a, a);
}
int main()
{
	long long a, b, c, d;
	cin >> a >> b >> c >> d;
	int ratio = gcd(c, d);
	d /= ratio;
	c /= ratio;
	int m = min(a / c, b / d);
	cout << c * m <<" "<< d * m << endl;
}
*/