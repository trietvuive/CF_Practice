/*
ID: triet_v1
LANG: C++
TASK: friday
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <map>
#include <vector>

using namespace std;
using ll = long long;

int get_day_in_month(int month, int year) {
	if(month == 2) {
		if(year % 4 == 0) {
			if(year % 100 == 0) {
				if(year % 400 == 0) return 29;
				else return 28;
			}
			else return 29;
		}
		else return 28;
	}
	else if(month == 4 || month == 6 || month == 9 || month == 11) return 30;
	else return 31;
}

void solve() {
	int month = 1, year = 1900;
	int n; cin >> n;
	vector<int> dates(7, 0);

	//Jan 13, 1900 is a Saturday
	int date = 0;
	while(year < 1900 + n) {
		dates[date]++;
		date = (date + get_day_in_month(month, year)) % 7;
		++month;
		if(month == 13) {
			month = 1;
			++year;
		}
	}
	
	for(int i = 0; i < 7; ++i) {
		cout << dates[i];
		if(i != 6) cout << ' ';
	}
	cout << endl;
}

int main() {
	freopen("friday.in", "r", stdin);
	freopen("friday.out", "w", stdout);
	int tc = 1;
	while(tc--) solve();
}

