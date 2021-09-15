#include<iostream>
#define ll long long
using namespace std;

int main()
{
	int cases;
	cin >> cases;
	while (cases--)
	{
		ll n, m, x;
		cin >> n >> m >> x;
		ll column = (x-1) / n, row = (x-1) % n;
		cout << m * row + column + 1 << endl;
	}
}
