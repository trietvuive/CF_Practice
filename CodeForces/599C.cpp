#include<bits/stdc++.h>
#include <unordered_map>
using namespace std;
const int MAX_N = 1e6 + 2;

long long a[MAX_N], b[MAX_N], n, element, sum, cnt;

int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; ++i)
		scanf("%d", &element), a[i] = element, b[i] = element;
	
	sort(a, a + n);

	for (int i = 0; i < n; ++i)
		sum += (a[i] - b[i]), cnt += sum == 0;
	cout << cnt << endl;

}