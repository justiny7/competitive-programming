//USACO January 2020 Contest - Bronze Problem 3

#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int K, N;
vector <int> X;


int main() {
	ofstream fout("race.out");
	ifstream fin("race.in");

	fin >> K >> N;
	for (int i = 0; i < N; i++) {
		int temp;
		fin >> temp;
		X.push_back(temp);
	}

	return 0;
}