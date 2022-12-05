#include<bits/stdc++.h>
using namespace std;
int n, m, k, a[200002];
bool sim(int start) {
	int rem_box = m, rem_size = k;
	while (rem_box && start <= n) {
		if (a[start] > k) return false;
		if (a[start] > rem_size) rem_size = k, --rem_box;
		else rem_size -= a[start++];
	}
	return start > n;
}
int main() {
	scanf("%d %d %d", &n, &m, &k);
	for (int i = 1; i <= n; ++i)
		scanf("%d", a + i);
	int left = 1, right = n + 1;
	while (left < right) {
		int mid = (left + right) / 2;
		if (sim(mid))
			right = mid;
		else
			left = mid + 1;
	}
	cout << n - left + 1 << endl;
}