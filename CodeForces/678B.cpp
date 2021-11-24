#include<bits/stdc++.h>
#define ll long long
using namespace std;

bool leap(int n) {
	return !(n % 4) && (n % 100 || !(n % 400));
}
ll get_day(int n) {
	return leap(n) ? 366 : 365;
}
int main()
{
	int n, start; cin >> n, start = n + 1;
	ll day = get_day(n);
	bool first_leap = leap(n);
	for (;!(leap(start) == first_leap && day % 7 == 0); day+=get_day(start++));
	cout << start << endl;
}