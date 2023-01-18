// Kadan's  Algo
// O(N)
#include <bits/stdc++.h>
using namespace std;

int max_sum = INT_MIN;
int kadansAlgo(int a[], int n)
{
    int curr_sum = 0;
    for (int i = 0; i < n; i++)
    {
        if (curr_sum < 0)
        {
            curr_sum = a[i];
        }
        else
            curr_sum += a[i];
        max_sum = max(curr_sum, max_sum);
    }
    return max_sum;
}

int main()
{
    int test;
    cin >> test;
    while (test--)
    {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        cout << kadansAlgo(a, n);
    }
    return 0;
}