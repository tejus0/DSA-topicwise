#include <bits/stdc++.h>
using namespace std;

void countPrimes(int n, int *primes)
{
    primes[0] = primes[1] = 0;
    primes[2] = 1;
    for (int i = 3; i <= n; i += 2)
    {
        primes[i] = 1;
    }
    for (int i = 3; i <= n; i += 2)
    {
        for (int j = i * i; j <= n; j += i)
        {
            primes[j] = 0;
        }
    }
}

int main()
{
    int test;
    cin >> test;
    int *primes = new int[5 * 106]{0};
    countPrimes(5 * 106, primes);
    while (test--)
    {
        int n;
        cin >> n;
        int ans = 0;
        for (int i = 0; i <= n; i++)
        {
            if (primes[i])
            {
                //  cout<<i<<" ";
                ans++;
            }
        }
        cout << ans;
    }
    return 0;
}
