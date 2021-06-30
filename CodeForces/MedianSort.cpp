/*#include<iostream>
#include<vector>

using namespace std;

void exchange(vector<int>& v)
{
	int left = 1, right = v.size(), next = v.size();
	while (left < right)
	{
		int result;
		int mid = (left + right) / 2;
		cout << v[left] <<" "<< v[mid] <<" "<< next << endl;
		cin >> result;
		if (result == v[left])
		{
			v.insert(v.begin() + left, next);
			return;
		}
		else if (result == v[mid])
		{
			if (right == mid + 1)
				left = right = mid+1;
			else
				left = mid;
		}
		else if (result == next)
		{
			if (left == mid - 1)
				left = right = mid;
			else
				right = mid;

		}
	}
	v.insert(v.begin() + left, next);
}
int main()
{
	int t, n, q;
	cin >> t >> n >> q;
	while (t--)
	{
		vector<int>v{0,1,2 };
		for (int i = 2; i < n; i++)
			exchange(v);
		for (int i = 1; i < v.size(); i++)
			cout << v[i] << " ";
		cout << endl;
		int response;
		cin >> response;
		if (response == -1)
			return 0;
	}
}
*/