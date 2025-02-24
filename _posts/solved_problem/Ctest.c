#include <stdio.h>
#include <stdlib.h>

int compareSequence(int *seq1, int len1, int *seq2, int len2) {
    int minLen = (len1 < len2) ? len1 : len2;
    for (int i = 0; i < minLen; i++) {
        if (seq1[i] != seq2[i])
            return (seq1[i] > seq2[i]) ? 1 : -1;
    }
    if (len1 == len2) return 0;
    return (len1 > len2) ? 1 : -1;
}

void computeB(int *lineup, int n, int *b, int *b_len) {
    int tempB[n];
    int len = 0;
    for (int i = n - 1; i >= 0; i--) {
        if (len == 0 || lineup[i] >= tempB[len - 1]) {
            tempB[len++] = lineup[i];
        }
    }
    for (int i = 0; i < len; i++) {
        b[i] = tempB[len - 1 - i];
    }
    *b_len = len;
}

int main() {
    int T;
    if (scanf("%d", &T) != 1) return 1;
    
    while (T--) {
        int N;
        if (scanf("%d", &N) != 1) return 1;
        
        int *FjFavCows = (int *)malloc(N * sizeof(int));
        for (int i = 0; i < N; i++) {
            scanf("%d", &FjFavCows[i]);
        }
        
        int *bestB = (int *)malloc(N * sizeof(int));
        int bestB_len = 0;
        computeB(FjFavCows, N, bestB, &bestB_len);
        
        for (int i = 0; i < N; i++) {
            int value = FjFavCows[i];
            int tempList[N - 1];
            int idx = 0;
            for (int k = 0; k < N; k++) {
                if (k == i) continue;
                tempList[idx++] = FjFavCows[k];
            }
            for (int j = 0; j <= i; j++) {
                int candidate[N];
                int pos = 0;
                for (int k = 0; k < j; k++) {
                    candidate[pos++] = tempList[k];
                }
                candidate[pos++] = value;
                for (int k = j; k < idx; k++) {
                    candidate[pos++] = tempList[k];
                }
                int candidateB[N];
                int candidateB_len = 0;
                computeB(candidate, N, candidateB, &candidateB_len);
                
                if (compareSequence(candidateB, candidateB_len, bestB, bestB_len) > 0) {
                    bestB_len = candidateB_len;
                    for (int k = 0; k < candidateB_len; k++) {
                        bestB[k] = candidateB[k];
                    }
                }
            }
        }
        
        for (int i = 0; i < bestB_len; i++) {
            printf("%d", bestB[i]);
            if (i < bestB_len - 1) printf(" ");
        }
        printf("\n");
        
        free(FjFavCows);
        free(bestB);
    }
    
    return 0;
}


