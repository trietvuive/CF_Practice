#include<iostream>
#include<unordered_map>

using namespace std;

int main()
{
	int cases;
	cin >> cases;
	for(int i = 1;i<=cases;i++)
	{
		int n, max_count = 0;
		cin >> n;
		unordered_map<int, int>count;
		count.reserve(n);
		for (int i = 0; i < n; i++)
		{
			int element;
			cin >> element;
			count[element]++;
			max_count = max(max_count, count[element]);
		}
		int result = max_count - (n - max_count);
		if (result <= 0)
			cout << n % 2 << endl;
		else
			cout << result << endl;
	}
}
