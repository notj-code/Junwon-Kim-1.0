#include <iostream>
using namespace std;

int main() {
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        long long ans = 0;
        for (long long i = 2; i <= n; i++) {
            int p = 1;
            while (10 * p <= i) {
                if ((i - p) / 10 >= p) {
                    ans++;
                    break;
                }
                p *= 10;
            }
        }
        cout << ans << endl;
    }
    return 0;
}
