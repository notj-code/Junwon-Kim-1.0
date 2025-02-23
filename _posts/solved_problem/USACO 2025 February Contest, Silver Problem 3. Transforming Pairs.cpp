#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

long long minOperations(long long a, long long b, long long c, long long d) {
    if (a == c && b == d) return 0;
    if ((c < a || d < b) || ((c - a) % b != 0 && (d - b) % a != 0)) return -1;

    vector<pair<long long, long long>> queue = {{a, b}};
    vector<pair<long long, long long>> next;
    long long steps = 0;

    while (!queue.empty()) {
        steps++;
        next.clear();
        for (auto& p : queue) {
            long long x = p.first, y = p.second;
            long long nx1 = x + y, ny1 = y;
            long long nx2 = x, ny2 = x + y;

            if (nx1 == c && ny1 == d) return steps;
            if (nx2 == c && ny2 == d) return steps;

            if (nx1 <= c && ny1 <= d) next.push_back({nx1, ny1});
            if (nx2 <= c && ny2 <= d) next.push_back({nx2, ny2});
        }
        queue = next;
    }

    return -1;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        long long a, b, c, d;
        cin >> a >> b >> c >> d;
        cout << minOperations(a, b, c, d) << endl;
    }
    return 0;
}
