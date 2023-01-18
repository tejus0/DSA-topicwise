#include <bits/stdc++.h>
using namespace std;

int main()
{
    int test;
    cin >> test;
    while (test--)
    {
        int n, k;
        cin >> n >> k;
        deque<int> dq;
        int *arr = new int[n];
        vector<int> ans;
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        for (int i = 0; i < k; i++)
        {
            while (!dq.empty() and dq.back() < arr[i])
            {
                dq.pop_back();
            }
            dq.push_back(arr[i]);
        }
        ans.push_back(dq.front());
        // cout<<ans.front()<<endl;
        // ans.pop_back();
        for (int i = k; i < n; i++)
        {
            if (dq.front() == arr[i - k])
            {
                dq.pop_front();
            }
            while (!dq.empty() and dq.back() < arr[i])
            {
                dq.pop_back();
            }
            dq.push_back(arr[i]);
            ans.push_back(dq.front());
        }
        for (auto i = ans.begin(); i != ans.end(); i++)
        {
            cout << *i << " ";
        }
        delete[] arr;
    }
    return 0;
}