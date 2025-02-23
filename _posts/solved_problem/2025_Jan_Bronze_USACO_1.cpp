#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    int T;
    cin >> T;
    while (T--) {
        int N, A, B;
        cin >> N >> A >> B;
        vector<string> photo(N);
        for (int i = 0; i < N; ++i) {
            cin >> photo[i];
        }

        vector<vector<int>> stars(N, vector<int>(N, 0));
        vector<vector<int>> shifted_stars(N, vector<int>(N, 0));

        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                if (photo[i][j] == 'B') {
                    stars[i][j] = 1;
                    shifted_stars[i][j] = 1;
                } else if (photo[i][j] == 'G') {
                    stars[i][j] = 1;
                }
            }
        }

        bool possible = true;
        int min_stars = 0;

        // Check for consistency
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                if (photo[i][j] == 'B') {
                    int shifted_i = i - B;
                    int shifted_j = j - A;
                    if (shifted_i >= 0 && shifted_i < N && shifted_j >= 0 && shifted_j < N) {
                        if (stars[shifted_i][shifted_j] != 1) {
                            possible = false;
                            break;
                        }
                    } else {
                        possible = false;
                        break;
                    }
                }
            }
            if (!possible) break;
        }

        if (!possible) {
            cout << -1 << endl;
            continue;
        }


        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                if (stars[i][j] == 1) {
                    min_stars++;
                }
            }
        }

        cout << min_stars << endl;
    }
    return 0;
}