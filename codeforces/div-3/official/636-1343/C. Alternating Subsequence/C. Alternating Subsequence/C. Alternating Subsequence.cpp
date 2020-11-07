#include <iostream>
#include <vector>

using namespace std;

bool pos(int a) {
	return (a > 0);
}

int main(void) {
	int t;
	cin >> t;

	vector <vector<int>> Arrays;
	for (int i = 0; i < t; i++) {
		vector<int> temp;
		int elements;
		cin >> elements;
		for (int j = 0; j < elements; j++) {
			int a;
			cin >> a;
			temp.push_back(a);
		}
		Arrays.push_back(temp);
	}

	for (int i = 0; i < t; i++) {
		bool target; //target sign - true = pos, false = neg
		long long int sum = 0, max;
		for (int j = 0; j < Arrays[i].size(); j++) {
			if (Arrays[i].size() == 1) sum = Arrays[i][j];
			else if (j == 0) {
				target = !pos(Arrays[i][j]);
				max = Arrays[i][j];
			}
			else {
				//cout << "sign: " << pos(Arrays[i][j]) << "\ttarg: " << target << endl;
				if (pos(Arrays[i][j]) == target || j == Arrays[i].size() - 1) {
					if (j == Arrays[i].size() - 1) {
						if (pos(Arrays[i][j]) == target) {
							sum += max;
							max = Arrays[i][j];
						}
						else {
							if (Arrays[i][j] > max) max = Arrays[i][j];
						}
					}

					sum += max;
					//cout << "Max: " << max << endl;
					max = Arrays[i][j];
					target = !target;
				}
				else {
					if (Arrays[i][j] > max) max = Arrays[i][j];
				}
			}
		}
		cout << sum << '\n';
	}

	return 0;
}