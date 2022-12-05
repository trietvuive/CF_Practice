#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main() 
{
	ll day, slimes;
	cin >> day >> slimes;
	int spit = 0;
	while (slimes)
	{
		if (slimes % 2)slimes /= 2;
		else ++spit, slimes = (slimes - 1) / 2;
	}
	cout << spit << endl;
}