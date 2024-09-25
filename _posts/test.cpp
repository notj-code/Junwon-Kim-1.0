
#include <bits/stdc++.h>
using namespace std;

int main() {
    deque<int> a;
    deque<int> aR;
    int buf;
    int sum = -100;
    for (int i=0; i<9; i++) {
        cin >> buf;
        a.push_back(buf);
        sum+=100;
    }

    sort(a.begin(), a.end());
    int breakAll=0;

    for (int i=0; i<9; i++) {
        if (breakAll) {break;}
        for (int j=0; j<9; j++) {
            if ((i != j)&&(sum ==  a[i]+a[j])) {
                int max = j > i ? j : i;
                int min = j < i ? j : i;
                a.erase(a.begin() + max);
                a.erase(a.begin() + min);

                breakAll = 1;
                break;
            }
        }
    }

    for (auto x: a) {
        cout << x << "\n";
    }
}