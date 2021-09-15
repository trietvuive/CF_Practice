#include<bits/stdc++.h>
using namespace std;
bool equal(const string& a, const string& b)
{
	for (int i = 0; i < min(a.size(), b.size()); i++)
		if (a[i] != b[i])
			return false;
	return true;
}
bool is_999(string& b, int idx)
{
	for (int i = idx; i < b.size(); ++i)
		if (b[i] != '9')
			return false;
	return true;
}
int ap(string& a, string& b)
{
	if (a.size() > b.size() || (a.size() == b.size() && a > b))
		return 0;
	int append = 0;
	bool is_equal = equal(a, b);
	int size_diff = b.size() - a.size();
	if (!is_equal)
	{
		if (a < b)
		{
			for (int i = 0; i < size_diff + 1; ++i)
				a += '0';
			return size_diff + 1;
		}
		else
		{
			for (int i = 0; i < size_diff; i++)
				a += '0';
			return size_diff;
		}
	}
	else
	{
		bool is_9 = is_999(b, a.size());
		if (is_9)
		{
			for (int i = 0; i < size_diff+1; i++)
				a += '0';
			return size_diff + 1;
		}
		else
		{
			for (int i = 0; i < size_diff - 1; i++)
				a += b[a.size()];
			a += b[a.size()] + 1;
			return size_diff;
		}
	}
	return -1;
}
int main()
{
	int t;
	cin >> t;
	for(int i = 1;i<=t;i++)
	{
		int N;
		cin >> N;
		string last_element = "0";
		int append = 0;
		for (int i = 0; i < N; i++)
		{
			string element;
			cin >> element;
			append += ap(element, last_element);
			last_element = element;
			//cout << last_element << endl;
		}
		cout << "Case #" <<i<<": " << append << endl;
	}
}