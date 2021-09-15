#include<iostream>
#include<vector>
using namespace std;

int main() {
	int cases;
	cin >> cases;
	while (cases--)
	{
		vector<int> v(101, 0);
		int n;
		cin >> n;
		for (int i = 0; i < n; i++)
		{
			int element;
			cin >> element;
			v[element]++;
		}
		for (int i = 0; i < 101; i++)
			if (v[i])
				cout << i << " ";
		for (int i = 0; i < 101; i++)
		{
			if (v[i])
			{
				for (int j = 0; j < v[i] - 1; j++)
					cout << i << " ";
			}
		}
		cout << endl;

	}
}
