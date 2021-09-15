#include<iostream>	
#include<vector>
#include<stack>
using namespace std;

int main()
{
	int cases;
	cin >> cases;
	while (cases--)
	{
		int n;
		cin >> n;
		vector<int> min_perm(n), max_perm(n);
		int min_idx = 1, max_idx = 1, last_cin = -1;
		stack<int>last_max_idx;
		vector<bool> min_used(n+1,false), max_used(n+1,false);
		for (int i = 0; i < n; i++)
		{
			int element;
			cin >> element;
			if (element == last_cin)
			{
				while (min_used[min_idx])min_idx++;
				min_perm[i] = min_idx;
				min_used[min_idx++] = true;
				if (max_used[max_idx])
				{
					while (!last_max_idx.empty() && max_used[last_max_idx.top()])
						last_max_idx.pop();
					if (!last_max_idx.empty())
					{
						max_idx = last_max_idx.top();
						last_max_idx.pop();
					}
					else
					{
						while (max_used[max_idx])max_idx--;
					}
				}
				max_perm[i] = max_idx;
				max_used[max_idx--] = true;
			}
			else
			{
				last_cin = element;
				min_perm[i] = element;
				max_perm[i] = element;
				last_max_idx.push(max_idx);
				max_idx = element - 1;
				min_used[element] = true;
				max_used[element] = true;
			}
		}
		for (int i = 0; i < n; i++)
			cout << min_perm[i] << " ";
		cout << endl;
		for (int i = 0; i < n; i++)
			cout << max_perm[i] << " ";
		cout << endl;
	}
}
