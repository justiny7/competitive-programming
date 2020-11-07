#include <iostream>
#include <vector>

using namespace std;



int main(void) {
	int t;
	cin >> t;
	for (int p = 0; p < t; p++) {
		int k, n;
		cin >> n >> k;

		int times = k/(n-1);
		int Mod = k % (n-1);
		if (Mod != 0) Mod++;
		int ans = (times-1) * n + (n - 1) + Mod;

		cout << ans << endl;

	}


	return 0;
}
