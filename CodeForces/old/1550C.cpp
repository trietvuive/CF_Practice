#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int MAX_N = 2e5 + 2;
int ar[MAX_N];
int main()
{
	int tc;
	cin >> tc;
	while (tc-- > 0)
	{
		int n; cin >> n;
		ll sum = 2 * n - 1; //subarray with 1 and 2 elements all qualify by default
		for (int i = 0; i < n; ++i)cin >> ar[i];
		for (int i = 0; i < n - 2; ++i)//subarray with 3 elements must not be non-decreasing or non-increasing
			if ((ar[i] < ar[i + 1] && ar[i + 1] > ar[i + 2]) || (ar[i] > ar[i + 1] && ar[i + 1] < ar[i + 2]))
				++sum;
		for (int i = 0; i < n - 3; ++i)//subarray with 4 must have 1st and last in the middle of 2nd and 3rd. Ex: 2 0 5 2
			if (max(ar[i], ar[i + 3]) < max(ar[i + 1], ar[i + 2]) && min(ar[i], ar[i + 3]) > min(ar[i + 1], ar[i + 2]))
				++sum;
		//it can be prove from induction that subarray with more than 4 elements will always be bad
		cout << sum << endl;
	}
}