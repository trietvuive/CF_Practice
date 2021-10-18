#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

int main()
{
	unordered_map<int, int> cnt;
	int n, max_cnt = 0, same_cnt = 0, last_same_cnt = 0;
	cin >> n;
	int max_idx = 0;
	for (int i = 0; i < n; ++i)
	{
		int element; cin >> element;
		++cnt[element];
		if (cnt[element] > max_cnt)
			last_same_cnt = same_cnt - 1, same_cnt = 1, max_cnt = cnt[element];

		//if an element reaches max_cnt, it used to be max_cnt - 1.
		else if (cnt[element] == max_cnt)++same_cnt, --last_same_cnt;
		else if (cnt[element] == max_cnt - 1)++last_same_cnt;

		//if max_cnt == 1, remove any element.
		//if max_cnt = 1 and every element is max_cnt - 1, remove one instance of the max_cnt element
		//if every element is max_cnt except for one element with count of 1, remove the lone element
		if (max_cnt == 1 || (same_cnt == 1 && last_same_cnt == cnt.size() - 1)
			|| (same_cnt == cnt.size() - 1 && i == same_cnt * max_cnt)) 
			max_idx = i + 1;
	}
	cout << max_idx << endl;
}