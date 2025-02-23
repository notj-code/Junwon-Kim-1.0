#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;
    vector<int> a(N + 1), b(N + 1);
    for (int i = 1; i <= N; ++i) {
        cin >> a[i];
    }
    for (int i = 1; i <= N; ++i) {
        cin >> b[i];
    }

    vector<int> prefix_old(N + 1, 0);
    for (int i = 1; i <= N; ++i) {
        prefix_old[i] = prefix_old[i - 1] + (a[i] == b[i]);
    }
    int initial_count = prefix_old[N];

    vector<vector<int>> dp(N + 2, vector<int>(N + 2, 0));

    for (int d = 1; d <= N; ++d) {
        for (int l = 1; l + d - 1 <= N; ++l) {
            int r = l + d - 1;
            if (d == 1) {
                dp[l][r] = (a[l] == b[l]);
            } else {
                dp[l][r] = (a[r] == b[l]) + (a[l] == b[r]);
                if (d > 2) {
                    dp[l][r] += dp[l + 1][r - 1];
                }
            }
        }
    }

    vector<int> ans(N + 1, 0);
    for (int l = 1; l <= N; ++l) {
        for (int r = l; r <= N; ++r) {
            int old = prefix_old[r] - prefix_old[l - 1];
            int new_m = dp[l][r];
            int c = initial_count - old + new_m;
            if (c >= 0 && c <= N) {
                ans[c]++;
            }
        }
    }

    for (int i = 0; i <= N; ++i) {
        cout << ans[i] << '\n';
    }

    return 0;
}