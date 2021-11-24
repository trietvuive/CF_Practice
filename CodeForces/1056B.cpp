#include <iostream>
long long n, m, i, a, j;
using namespace std;
int main() {
	cin >> n >> m; 
	for (; ++i <= m;)
		for (j = 0; ++j <= m;)
			if ((i * i + j * j) % m == 0 && n >= i && n >= j)
				a += ((n - i + m) / m) * ((n - j + m) / m); 
	cout << a;
}