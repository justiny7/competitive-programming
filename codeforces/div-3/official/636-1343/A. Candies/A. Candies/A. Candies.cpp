#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main(void) {
	int t;
	cin >> t;
	vector <int> N(t);
	int pow2[30];

	for (int i = 0; i < t; i++) cin >> N[i];
	for (int i = 1; i <= 30; i++) pow2[i - 1] = pow(2, i) - 1;
	//for (int i = 0; i < 30; i++) cout << pow2[i] << endl;

	for (int i = 0; i < N.size(); i++) {
		for (int j = 1; j < 30; j++) {
			if (N[i] % pow2[j] == 0) {
				cout << N[i] / pow2[j] << '\n';
				break;
			}
		}
	}

	return 0;
}