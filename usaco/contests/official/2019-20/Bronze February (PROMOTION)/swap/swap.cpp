//Problem 3

#include <iostream>
#include <numeric>
#include <algorithm>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

int main() {
	ofstream fout("swap.out");
	ifstream fin("swap.in");

	int N, K;
	int repeatPoint = 0;
	int A1, A2, B1, B2;
	fin >> N >> K >> A1 >> A2 >> B1 >> B2;

	vector <int> v(N);
	iota(begin(v), end(v), 1);
	vector <int> original = v;

	for (int i = 0; i < K; i++) {
		reverse(v.begin() + A1 - 1, v.begin() + A2);
		reverse(v.begin() + B1 - 1, v.begin() + B2);

		//for (int i = 0; i < N; i++) cout << v[i];
		//cout << endl;
		if (v == original) {
			repeatPoint = i + 1;
			break;
		}
	}
	if (repeatPoint != 0) {
		for (int i = 0; i < K%repeatPoint; i++) {
			reverse(v.begin() + A1 - 1, v.begin() + A2);
			reverse(v.begin() + B1 - 1, v.begin() + B2);

			//for (int i = 0; i < N; i++) cout << v[i];
			//cout << endl;
		}
	}
	for (int i = 0; i < N; i++) {
		cout << v[i];
		fout << v[i] << '\n';
	}
	cout << "\n\n" << repeatPoint;

	return 0;
}