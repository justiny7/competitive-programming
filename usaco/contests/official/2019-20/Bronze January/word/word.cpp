//USACO January 2020 Contest - Bronze Problem 1

#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

vector <string> essay;
int N, K;

int main() {
	ofstream fout("word.out");
	ifstream fin("word.in");

	fin >> N >> K;

	for (int i = 0; i < N; i++) {
		string temp;
		fin >> temp;
		essay.push_back(temp);
	}
	int lineChar = 0;
	for (int i = 0; i < N; i++) {
		if (i == 0) {
			lineChar += essay[i].length();
			fout << essay[i];
		}
		else {
			lineChar += essay[i].length();
			if (lineChar > K) {
				fout << "\n" << essay[i];
				lineChar = essay[i].length();
			}
			else fout << " " << essay[i];
		}
	}
	fout << "\n";

	return 0;
}