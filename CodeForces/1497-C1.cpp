#include<vector>
#include<algorithm>
#include<iostream>
/*
using namespace std;
void solve(int n, int k);
void solve_3(int n, int factor);
int main()
{
	int cases;
	cin >> cases;
	for (int i = 0; i < cases; i++)
	{
		int n, k;
		cin >> n >> k;
		solve(n,k);
	}
}
void solve(int n, int k)
{
	if (k == 3)
		solve_3(n, 1);
	else {
		for(int i = 0;i<k-3;i++)
			cout << 1 << " ";
		solve_3(n - (k-3), 1);
	}
}
void solve_3(int n, int factor)
{
	if (n == 4)
		cout << factor <<" "<< factor << " "<<2 * factor << endl;
	else if (n % 2 == 1)
	{
		cout << 1 * factor << " "<<(n / 2) * factor <<" "<< (n / 2) * factor << endl;
	}
	else
		solve_3(n / 2, factor * 2);
}
*/