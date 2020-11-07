#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main(void) {
	int t;
	cin >> t;

	vector<int> lengths(t);
	for (int i = 0; i < t; i++) cin >> lengths[i];
	//for (int i = 0; i < lengths.size(); i++) cout << lengths[i] << " ";

	for (int i = 0; i < t; i++) {
		if ((lengths[i] / 2) % 2 != 0)
			cout << "NO\n";
		else {
			cout << "YES\n";
			long long int evenSum;
			long long int buffer = lengths[i]/2;
			evenSum = buffer * (buffer + 1);
			
			for (int j = 0; j < (lengths[i] / 2); j++) {
				cout << 2 + 2 * j << " ";
			}
			for (int j = 0; j < ((lengths[i] / 2) - 1); j++)
				cout << 1 + 2 * j << " ";
			cout << evenSum - pow((lengths[i] / 2 - 1), 2) << '\n';
		}
	}

	return 0;
}