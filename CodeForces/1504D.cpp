#include<iostream>
using namespace std;
int n, i, a, x, y, c[2];
using namespace std;
void calc() {
    cin >> a;
    //go to 1 if 0 if already used up 0
    //or still have 1 and a isn't 1
    x = (c[1] < n * n && a != 1) || c[0] >= n * n;
    //if ban 1, spam 2 until fill the map. mode 0
    //if not, keep spamming 1 until fill the map, then fill in 2 and 3 between the gap. mode 1
    //if 1 or 2 is ban during critical position, fill 3 in as last resort
    y = x ? (a == 1 ? 3 : 1) : (a == 2 ? 3 : 2);
    printf("%d %d %d\n", y, c[x] / n + 1, c[x] % n + 1);
    cout.flush();
    //skip 2 since you wanna alternate
    c[x] += 2;
    //jump backward if at second square & even board & not same row
    //jump forward if at first square & even board & not same row cuz you're crashing first element
    //if odd board, no need to adjust. You will never crash with element above you while jumping 2
    c[x] += (c[x] % n ? -1 : 1) * !(n % 2 || c[x] / n == (c[x] - 2) / n);
}

int main() {
    cin >> n;
    c[0] = 0;
    c[1] = 1;
    for (i = 1; i <= n * n; i++)
        calc();
}
