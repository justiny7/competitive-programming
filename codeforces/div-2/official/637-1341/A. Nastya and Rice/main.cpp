#include <iostream>
#include <vector>

using namespace std;

int main(void) {
	int t;
	cin >> t;

	vector<int>a (t), b (t), c (t), d (t);
	vector<int> count (t);

	for (int i = 0; i < t; i++) {
		cin >> count[i] >> a[i] >> b[i] >> c[i] >> d[i];
	}
	bool yes = false;
	for (int i=0; i < t; i++) {
		int low = (c[i]-d[i]) / count[i];
		if ((c[i]-d[i])%count[i] != 0) low++;

		int high = (c[i]+d[i]) / count[i];


		if ((a[i]+b[i]) >= low && high >= (a[i]-b[i]))
			cout << "Yes\n";
		else cout << "No\n";

	}

	return 0;
}