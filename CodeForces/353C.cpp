#include<iostream>
using namespace std;
const int MAX_N = 1e5 + 2;
int a[MAX_N];
//the problem boils down to: Given binary s (101010), all "max_configurations" are:
// 101010, 01111, 10011, 101001. Basically, if s[i] == 1, either pick 1 like s or make that bit 0 and make everything after it 1
int main() 
{ 
	string s;
	//sum will keep cumulating sum of left if pick like s, along with sum of everything to the right (in case any 1 wanna be the turning point)
	int n, i, ans = 0, sum = 0; 
	cin >> n;
	for (i = 0; i < n; i++) 
	{
		cin >> a[i];
		sum += a[i];
	}
	cin >> s;
	//Note that s is reverse, and the LSB is on the left, not right
	for (i = n - 1; i > -1; i--)
		if (s[i] == '1')
			//pick 1 or 0. 0 can make all bits after it 1, 1 will just follow s
			ans = max(ans, sum - a[i]); 
		else sum -= a[i];
	cout << max(ans, sum);
	return 0; 
}