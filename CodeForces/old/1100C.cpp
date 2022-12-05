#include "bits/stdc++.h"
using namespace std;
const long double PI = acos(-1);
int main()
{
	double n, R;
	cin >> n >> R;
	cout.precision(10);
	cout << R * sin(PI / n) / (1 - sin(PI / n));
}