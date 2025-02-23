#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, m;
    bool check = false;
    vector<int> v;
    cin >> m >> n;

    for (int i = 1; i <= 10000; i++)
    {
        if ((i * i >= m) && (i * i <= n))
        {
            v.push_back(i * i);
            check = true;
        }
    }

    if (check)
    {
        sort(v.begin(), v.end());
        int sum = 0;
        for (auto x : v)
        {
            sum += x;
        }
        cout << sum << "\n";
        cout << v[0];
    }
    else
    {
        cout << -1;
    }
}