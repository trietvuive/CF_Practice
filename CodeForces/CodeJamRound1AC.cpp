/*#include<bits/stdc++.h>

using namespace std;
int main()
{
	int t;
	cin >> t;
	for (int i = 1; i <= t; ++i)
	{
		string max_ans;
		int max_score = 0;
		int N, Q;
		cin >> N >> Q;
		for (int j = 0; j < N; j++)
		{
			int score;
			string ans;
			cin >> ans >> score;
			if (score > max_score)
				max_ans = ans, max_score = score;
		}
		cout << "Case #" << i << ": " << max_ans << " " << max_score << "/1" << endl;
	}
}
*/