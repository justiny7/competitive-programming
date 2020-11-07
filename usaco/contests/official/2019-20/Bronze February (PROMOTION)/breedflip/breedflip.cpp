//Problem 2

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

int main() {
	ofstream fout("breedflip.out");
	ifstream fin("breedflip.in");

	int N;
	fin >> N;

	vector <char> original;
	vector <char> newOrder;
	int flips = 0;
	bool last = false;

	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < N; j++) {
			char a;
			fin >> a;
			if (i == 0) original.push_back(a);
			else newOrder.push_back(a);
		}
	}
	for (int i = 0; i < N; i++) {
		if (original[i] != newOrder[i] && i == 0) {
			last = true;
			flips++;
		}
		else if (original[i] == newOrder[i] && last == true) last = false;
		else if (original[i] != newOrder[i] && last == false) {
			last = true;
			flips++;
		}
	}
	cout << flips;
	fout << flips << '\n';
	return 0;
}