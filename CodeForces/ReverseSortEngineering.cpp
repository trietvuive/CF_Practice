/*#include<iostream>
#include<vector>
using namespace std;

void swap(vector<int>& vec, int start, int end)
{
	while (start < end)
	{
		int temp = vec[start];
		vec[start++] = vec[end];
		vec[end--] = temp;
	}
}
void swap_vector(vector<int>& vec, const vector<pair<int,int>>& swapvec)
{
	for(int i = swapvec.size()-1; i >= 0; i--)
		swap(vec, swapvec[i].first, swapvec[i].second);
}
int main()
{
	int cases;
	cin >> cases;
	for (int i = 1; i <= cases; i++)
	{
		int n, cost;
		cin >> n >> cost;
		if (cost > (n + 1) * n / 2 - 1 || cost < n - 1)
		{
			cout << "Case #" << i << ": IMPOSSIBLE" << endl;
			continue;
		}
		vector<int> v(n+1);
		for (int i = 1; i <= n; i++)
			v[i] = i;
		vector<pair<int,int>>swap(n - 1);
		for (int i = n - 2; i >= 0; i--)
		{
			int start = i + 1;
			int max_allocated = cost - i;
			int end = min(start + max_allocated - 1, n);
			cost -= (end - start + 1);
			swap[i] = { start,end };
		}
		swap_vector(v, swap);
		cout << "Case #" << i << ": ";
		for (size_t i = 1; i <= n; i++)
			cout << v[i] << " ";
		cout << endl;
	}
}
*/