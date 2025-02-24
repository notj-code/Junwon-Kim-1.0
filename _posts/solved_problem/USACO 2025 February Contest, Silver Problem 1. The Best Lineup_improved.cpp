#include <bits/stdc++.h>
using namespace std;

vector<int> computeB(const vector<int>& lineup) {
    vector<int> b;
    int N = lineup.size();
    for (int i = N - 1; i >= 0; i--) {
        if (b.empty() || lineup[i] >= b.back())
            b.push_back(lineup[i]);
    }
    reverse(b.begin(), b.end());
    return b;
}

vector<int> solve(vector<int>& cows) {
    int N = cows.size();
    vector<int> best = computeB(cows);
    for (int i = 0; i < N; i++) {
        int tmp = cows[i];
        cows.erase(cows.begin() + i);
        for (int pos = 0; pos <= i; pos++) {
            cows.insert(cows.begin() + pos, tmp);
            vector<int> candidate = computeB(cows);
            if (candidate > best)
                best = candidate;
            cows.erase(cows.begin() + pos);
        }
        cows.insert(cows.begin() + i, tmp);
    }
    return best;
}

int main(){
    int T;
    scanf("%d", &T);
    while (T--){
        int N;
        scanf("%d", &N);
        vector<int> cows(N);
        for (int i = 0; i < N; i++){
            scanf("%d", &cows[i]);
        }
        vector<int> res = solve(cows);
        for (int i = 0; i < res.size(); i++){
            printf("%d%c", res[i], (i < res.size() - 1) ? ' ' : '\n');
        }
    }
    return 0;
}