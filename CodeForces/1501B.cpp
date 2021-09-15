#include<iostream>
#include<vector>
#include<stack>
using namespace std;
int main() {
	int cases;
	cin >> cases;
	for (int i = 0; i < cases; i++)
	{
		int layer;
		cin >> layer;
		stack<int> not_drenched;
		for (int i = 0; i < layer; i++)
		{
			int cream;
			cin >> cream;
			if (cream == 0)
				not_drenched.push(i);
			else
			{
				while (!not_drenched.empty() && not_drenched.top() > i - cream)
					not_drenched.pop();
			}
		}
		vector<int> cake(layer, 1);
		for (int i = layer - 1; i > -1; i--)
		{
			if (!not_drenched.empty() && not_drenched.top() == i)
			{
				cake[i] = 0;
				not_drenched.pop();
			}
		}
		for (int i = 0; i < layer; i++)
			cout << cake[i] << " ";
		cout << endl;

	}
}
