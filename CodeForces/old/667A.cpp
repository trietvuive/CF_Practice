#include<bits/stdc++.h>
const double pi = 3.14159265358979323846;
using namespace std;

int main() {
	setprecision(20);
	double d, h, r, start, in, out;
	cin >> d >> h >> out >> in;
	r = d / 2, start = r * r * pi * h, in = r * r * pi * in;
	if (in >= out)
		cout << "NO\n";
	else
	{
		double time = start / (out - in);
		cout.precision(9);
		cout << "YES\n" << time << endl;
	}
}