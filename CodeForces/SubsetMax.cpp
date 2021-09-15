#include <iostream>
#include <vector>
#include <map>
using namespace std;
int main()
{
	int test = 0;
	cin >> test;
	vector<int> answer;
	for (int i = 0; i < test; i++)
	{
		int n;
		cin >> n;
		map<int, int> counter;
		for (int i = 0; i < n; i++)
		{
			int number;
			cin >> number;
			if (counter.count(number) == 1)counter[number]++;
			else
				counter.insert({ number,1 });

		}
		int mex1 = -1;
		int mex2 = -1;
		bool set1 = false;
		bool set2 = false;
		for (int i = 0; i < n+1; i++)
		{
			if (counter.count(i) == 0)
			{
				if (!set1)
					mex1 = i;
				if (!set2)
					mex2 = i;
				break;
			}
			if (counter[i] == 1 && !set1 && !set2)
			{
				if (!set1)
				{
					mex1 = i;
					set1 = true;
				}
				else
				{
					mex2 = i;
					set2 = true;
				}
			}
		}
		answer.push_back(mex1 + mex2);
	}
	for (int i : answer)
	{
		cout << i << endl;
	}
	return 0;
}