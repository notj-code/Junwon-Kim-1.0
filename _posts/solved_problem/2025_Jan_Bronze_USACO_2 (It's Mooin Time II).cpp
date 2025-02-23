#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;
    vector<int> a(N);
    unordered_map<int, vector<int>> pos;
    for (int i = 0; i < N; ++i) {
        cin >> a[i];
        pos[a[i]].push_back(i);
    }

    unordered_map<int, int> first_oc;
    vector<int> sorted_first_occs;
    for (const auto& p : pos) {
        int x = p.first;
        first_oc[x] = p.second[0];
        sorted_first_occs.push_back(p.second[0]);
    }
    sort(sorted_first_occs.begin(), sorted_first_occs.end());

    long long ans = 0;

    for (const auto& p : pos) {
        int y = p.first;
        const auto& v = p.second;
        int k = v.size();
        if (k < 2) continue;

        int cutoff_idx = k - 2;
        int cutoff_pos = v[cutoff_idx] - 1;

        int cnt = upper_bound(sorted_first_occs.begin(), sorted_first_occs.end(), cutoff_pos) - sorted_first_occs.begin();

        if (first_oc[y] <= cutoff_pos) {
            cnt--;
        }

        ans += cnt;
    }

    cout << ans << '\n';

    return 0;
}