#include<bits/stdc++.h>
using namespace std;

int main() {
  int arr[100][100], n, cnt=0;
  for (int i=0; i<100; i++) {
    for (int j=0; j<100; j++) {
      arr[i][j] = 1;
    }
  }
  cin >> n;
  int l[n], d[n];
  for (int i=0; i<n; i++) {
    cin >>l[i] >> d[i];
  }

  for (int i=0; i<n; i++) {
    for (int j=0; j<l[i]; j++) {
      for (int k=0; k<d[i]; k++) {
        arr[j][k] = 0;
      }
    } 
  }

  for (int i=0; i<100; i++) {
    for (int j=0; j<100; j++) {
      cnt += arr[i][j];
    }
  }

  cout << cnt;
}