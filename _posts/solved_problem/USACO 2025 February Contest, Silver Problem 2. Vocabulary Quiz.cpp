#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
    
    int Q;
    cin >> Q;
    while (Q--) {
        int K;
        cin >> K;
        
        int count = 0;
        for (int i = 0; i < N; i++) {
            for (int j = i + 1; j < N; j++) {
                if (A[i] == A[j]) {
                    if (j - i <= K) count++;
                }
            }
        }
        cout << count << "\n";
    }
    return 0;
}
