#include<bits/stdc++.h>
using namespace std;
long long i, a, n, l, d; 
string s, z; 
main() { 
	cin >> s >> z; 
	n = s.size(); 
	d = z.size() - n + 1; 
	for (i = 0; i < d; ++i)
		l += z[i] - '0'; 
	a = (s[0] == '0') ? l : d - l; 
	for (i = 1; i < n; ++i) { 
		l -= z[i - 1] - '0'; 
		l += z[d - 1 + i] - '0'; 
		a += (s[i] == '0') ? l : d - l; 
	}
	cout << a; 
}