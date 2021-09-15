#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n = 1;
	int P, M;
	cin >> P >> M;
	int finish_round_turn = 0;
	while (M > 4 * n)M -= 4 * n++, finish_round_turn += 4 * (n-1);
	int order = 1;
	if (M > n)M -= n, ++order;
	else M = 0;
	if (M > n) M -= n, ++order;
	else M = 0;
	if (M) order = 4 - M % 2;
	finish_round_turn += (n) * 4;
	int player = (finish_round_turn-1)%P+1;
	if (order == 1)cout << "Efficiency" << endl;
	else if (order == 2)cout << "Unbreaking" << endl;
	else if (order == 3)cout << "Silk" << endl;
	else if (order == 4)cout << "Touch" << endl;
	cout << player << endl;
}