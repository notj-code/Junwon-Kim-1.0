#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	cin >> n;
	vector<int> v(n);
	for (int i=0; i<n; i++) {
		v[i] = i+1;
	}
	if (n<4) {
		cout << "NO SOLUTION";
	} else if (n%2==0) {
		for (int i=0;i<n/2;i++) {
			cout << v[i] << " " << v[i+n/2] << " ";
		}
	} else if (n%2!=0) {
			for (int i=0; i<(n-1)/2; i++) {
				cout << v[i] << " " <<v[n-i-1]<< " ";
			}
			cout << v[(n-1)/2] << " ";
		}
}