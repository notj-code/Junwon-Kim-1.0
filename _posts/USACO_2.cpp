#include <bits/stdc++.h>

using namespace std;

int main() {
    int main
}

while (!a.empty())
{
    if (b.empty() || a[0] >= b.back())
    {
        b.push_back(a[0]);
    }
    a.erase(a.begin());
}

//밑에서 부터 get b 함수 만들거임
vector<int> get_b(vector<int> a)
{
    vector<int> b;
    while (!a.empty())
    {
        if (b.empty() || a[0] >= b.back())
        {
            b.push_back(a[0]);
        }
        a.erase(a.begin());
    }
    return b;
}
    

