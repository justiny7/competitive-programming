#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;
	for (int i = 0; i < t; i++) {
		int n, layercnt = 1;
		cin >> n;
		int pyramids = 0;
		while (n > 1) {
			if (n - (layercnt * 3 - 1) >= 0) {
				n -= layercnt * 3 - 1;
				layercnt++;
			}
			else {
				pyramids++;
				layercnt = 1;
			}
			if (n == 0 || n == 1) {
				pyramids++;
				layercnt = 1;
			}
		}
		cout << pyramids << endl;
	}

	return 0;
}