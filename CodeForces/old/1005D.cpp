#include<bits/stdc++.h>
using namespace std;

int main() {
	string s;
	cin >> s;
	int cnt = 0, mask = 0, cur_sum = 0;
	for (int i = 0; i < s.size(); ++i)
	{
		int num = s[i] - '0';
		cur_sum = (cur_sum + num) % 3;
		if (cur_sum == 0 || (1 << cur_sum) & mask)++cnt, mask = 0, cur_sum = 0;
		else
			mask |= 1 << cur_sum;
	}
	printf("%d\n", cnt);
}