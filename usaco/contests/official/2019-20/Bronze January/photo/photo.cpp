//USACO January 2020 Contest - Bronze Problem 2

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int N;
vector <int> perm;


int main() {
	ofstream fout("photo.out");
	ifstream fin("photo.in");

	fin >> N;
	for (int i = 0; i < N - 1; i++) {
		int temp;
		fin >> temp;
		perm.push_back(temp);
	}
	bool works = false;
	bool isRepeat = false;
	vector <int> sequence (N);
	int startCount = 1;
	int repeats = 0;
	while (!works) {
		repeats = 0;
		for (int i = 0; i < N; i++) {
			if (i == 0) {
				sequence[0] = startCount;
			}
			else {
				sequence[i] = perm[i - 1] - sequence[i - 1];
			}
			cout << sequence[i] << " ";
		}

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (i != j) {
					if (sequence[i] == sequence[j]) {
						repeats++;
					}
				}
				if (sequence[i] <= 0) repeats++;
			}
		}
		repeats /= 2;
		cout << repeats;
		if (repeats != 0) {
			works = false;
			startCount++;
		}
		else if (repeats == 0) {
			for (int i = 0; i < N-1; i++) fout << sequence[i] << " ";
			fout << sequence[N-1] << "\n";
			works = true;
		}
		cout << endl;
	}

	return 0;
}