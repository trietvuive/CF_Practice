#include <bits/stdc++.h>

using namespace std;

//Target: You need all columns to have even number of squares left after filling out horizontal dominoes. Else you already fail.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m, k;
        cin >> n >> m >> k;
        int h = n * (m / 2);//number of dominoes need to be filled. exclude odd last column if exist
        cout << ((k > h || k % 2 != h % 2 || ((n - n % 2) * (m - m % 2) / 2 < h - k)) ? "NO" : "YES") << endl;
        //k>h: 3x7 matrix and you have to fill more than 18 squares with horizontal domino. Muri

        //k%2 != h%2: 
        //if h is odd, n (row) is odd and you can fill a row with odd number of horizontal dominoes (note that m is not odd since n*m must be even).
        //Then, you fill so that all columns have even number of squares left (column are nx1 vector). You need odd k to do this since m/2 is odd and you need to fill an odd number of squares in all columns (odd - odd = even).

        //Vice versa, if h is even, then either n (row) is even or m/2 is even.
        //you still need to leave all columns with even number of squares left. You need even k to do this since either m/2 is even or you need to fill an even number of squares in all columns (even - even = even).

        //(m-m%2) * (n-n%2) / 2 < h - k:
        //If the amount of row is odd and you don't even have enough k to fill out the first row, you already lost.
        //If n is even, it's business as usual. Note that this expression will always be false if n is even (left side will basically be = h).
    }
}
