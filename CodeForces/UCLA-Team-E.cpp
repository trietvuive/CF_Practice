/*#include<bits/stdc++.h>
using namespace std;

int main()
{
	int a_left = 1, a_right = 500, b_left = 1, b_right = 500;
	while (a_left != a_right || b_left != b_right)
	{
		if (a_left == b_left)
		{
			string a_rep, b_rep;
			int mid = (a_right + a_left - 1) / 2;
			cout << "ASK " << a_left << " " << mid << endl;
			cin >> a_rep >> b_rep;
			if (a_rep == "yes")
				a_right = mid;
			else
				a_left = mid + 1;
			if (b_rep == "yes")
				b_right = mid;
			else
				b_left = mid + 1;
		}
		else
		{
			int a_mid = (a_right + a_left+1) / 2;
			int b_mid = (b_right + b_left+1) / 2;
			if (b_mid > a_mid)
				cout << "ASK " << a_mid << " " << --b_mid << endl;
			else
				cout << "ASK " << b_mid << " " << --a_mid << endl;
			string a_rep, b_rep;
			cin >> a_rep >> b_rep;
			if (a_rep == "yes")
				if (b_mid > a_mid)
					if (a_left == a_mid && a_left != a_right)a_right--;
					else a_left = a_mid;
				else
					if (a_right == a_mid && a_left != a_right) a_left++;
					else a_right = a_mid;
			else
				if (b_mid > a_mid) a_right = a_mid - 1;
				else a_left = a_mid+1;

			if (b_rep == "yes")
				if (a_mid > b_mid)
					if (b_left == b_mid && b_left != b_right) b_right--;
					else b_left = b_mid;
				else
					if (b_right == b_mid && b_left != b_right) b_left++;
					else b_right = b_mid;
			else
				if (a_mid > b_mid)b_right = b_mid - 1;
				else b_left = b_mid+1;

		}
	}
	cout << "GUESS " << a_left << " " << b_left << endl;
}
*/