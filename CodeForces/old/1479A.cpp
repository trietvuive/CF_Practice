#include<bits/stdc++.h>
using namespace std;
int main() {
	int n; cin >> n;
	int left = 1, right = n;
	while (left < right) {
		int mid = (left + right) / 2;
		int mid_val, next_mid;
		printf("? %d\n? %d\n", mid, mid + 1);
		fflush(stdout);
		cin >> mid_val >> next_mid;
		if (mid_val > next_mid)
			left = mid + 1;
		else
			right = mid;
	}
	printf("! %d", left);
	fflush(stdout);

}