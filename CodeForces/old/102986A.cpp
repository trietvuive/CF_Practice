#include<iostream>
const int MAX = 10e9 + 2;
using namespace std;

int main()
{
	int n;
	cin >> n;
	int lowest = MAX, highest = -MAX;
	string lowest_food, highest_food;
	for (int i = 0; i < n; i++)
	{
		string food;
		int value;
		cin >> food >> value;
		if (value > highest)
			highest = value, highest_food = food;
		if (value < lowest)
			lowest = value, lowest_food = food;
	}
	cout << lowest_food << " " << highest_food << endl;

}