#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main(void) {
	int t;
	cin >> t;

	for (int i = 0; i < t; i++) {
		int a;
		cin >> a;
		int sum1 = 0, sum2 = 0;
		int counter2 = a/2;
		//cout << counter1 << " " << counter2 << endl;

		for (int j = a; j >= 1; j--) {
			if (j == a) {
				sum1 += pow(2, j);
			}
			else if (counter2 != 0) {
				sum2 += pow(2, j);
				counter2--;
			}
			else {
				sum1 += pow(2, j);
			}

		}
		cout << abs(sum1 - sum2) << endl; 
	}


	return 0;
}