/*#include<iostream>

using namespace std;
int n, arr[102];

void reverse(int start, int end)
{
    while (start < end)
    {
        int temp = arr[end];
        arr[end--] = arr[start];
        arr[start++] = temp;
    }
}
int cost()
{
    int cost = 0;
    for (int i = 0; i < n-1; i++)
    {
        int min_idx = i;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[min_idx])min_idx = j;
        }
        reverse(i, min_idx);
        cost += (min_idx - i) + 1;
    }
    return cost;
}
int main()
{
    int cases;
    cin >> cases;
    for (int i = 1; i <= cases; i++)
    {
        cin >> n;
        for (int i = 0; i < n; i++)
            cin >> arr[i];
        cout << "Case #" << i << ": " << cost() << endl;
    }
}
*/