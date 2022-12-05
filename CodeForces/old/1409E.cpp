#include<bits/stdc++.h>
using namespace std; 
int t, n, k, x[400000], a[200000], s, m, l, i, r; 
int main() { 
	cin >> t; 
	while (t--) { 
		cin >> n >> k; 
		for (i = 0; i < 2 * n; i++)
			cin >> x[i]; 
		sort(x, x + n); 
		s = l = m = 0; 
		for (r = 0; r < n; r++) { 
			while (x[r] - x[l] > k)
				m = max(m, a[l++]); 
			a[r] = r - l + 1;
			s = max(s, m + a[r]); 
		}
		cout << s << '\n'; 
	}
}