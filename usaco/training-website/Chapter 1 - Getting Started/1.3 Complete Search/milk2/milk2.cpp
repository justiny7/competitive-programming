/*
ID: justiny7
TASK: milk2
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int max(vector <int> a) {
	int b = 0;
	for (int i = 0; i < a.size(); i++) if (a[i] > b) b = a[i];
	return b;
}

int main() {
	ofstream fout("milk2.out");
	ifstream fin("milk2.in");

	int N;
	int M;
	fin >> N;

	vector <int> timeStart;
	vector <int> timeEnd;
	vector <int> state;

	for (int i = 0; i < N; i++) {
		int temp1, temp2;
		fin >> temp1 >> temp2;
		timeStart.push_back(temp1);
		timeEnd.push_back(temp2);
	}
	M = max(timeEnd);
	for (int i = 0; i < M + 1; i++) {
		state.push_back(0);
	}
	for (int k = 0; k < N; k++) {
		for (int i = 0; i < M; i++) {
			if (i < timeEnd[k] && i >= timeStart[k]) state[i] += 1;
		}
	}
	int leastCounter = 0, mostCounter = 0;
	int least = 0, most = 0;
	for (int i = 0; i < M; i++) {
		if (state[i] == 0 && i > timeStart[0]) {
			leastCounter++;
			if (state[i + 1] != 0) {
				if (leastCounter > least) least = leastCounter;
				leastCounter = 0;
			}
		}
		else if (state[i] >= 1) {
			mostCounter++;
			if (state[i + 1] == 0) {
				if (mostCounter > most) most = mostCounter;
				mostCounter = 0;
			}
		}
	}
	cout << most << endl << least << endl;
	fout << most << " " << least << "\n";

	return 0;
}