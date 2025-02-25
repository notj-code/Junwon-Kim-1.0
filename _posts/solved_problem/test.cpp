#include <iostream>
#include <vector>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int N;
  cin >> N;
  vector<int> contest(N);
  for (int i = 0; i < N; i++) {
    cin >> contest[i];
  }

  // Since each contest integer is in the range [1, N], create arrays of size N+1.
  vector<int> freq(N + 1, 0);
  vector<bool> seen(N + 1, false);
  int distinctCount = 0;
  long long answer = 0; // Use 64-bit integer for the final count

  // Traverse the contest array to count distinct moos.
  for (int i = 0; i < N; i++) {
    int val = contest[i];
    // Mark the number as seen and update distinct count if it's the first occurrence.
    if (!seen[val]) {
      seen[val] = true;
      distinctCount++;
    }
    freq[val]++;

    // When we encounter the second occurrence of val, every distinct number seen so
    // far (except val itself) can serve as the first element x in a moo (x, val,
    // val). Add them to the answer.
    if (freq[val] == 2) {
      answer += (distinctCount - 1);
    }
  }

  cout << answer << "\n";
  return 0;
}