//USACO Bronze 2019 December Contest Problem 2

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

int N;
char list[100];

struct testString {
	string name;
	int times = 0;
};

vector <testString> testCases;

int main() {
	ofstream fout("whereami.out");
	ifstream fin("whereami.in");
	
	fin >> N;
	for (int i = 0; i < N; i++) fin >> list[i];

	string str(list);
	bool isRepeat = false;
	int counter = 0;
	int answer = 0;

	for (int i = 1; i <= N; i++) {
		for (int j = 0; j <= N - i; j++) {
			testString test;
			test.name = str.substr(j, i);
			cout << test.name << endl;
			if (j == 0) testCases.push_back(test);
			else {
				for (int c = 0; c < testCases.size(); c++) {
					if (testCases[c].name == test.name) {
						testCases[c].times++;
						isRepeat = true;
					}
				}
				if (!isRepeat) {
					testCases.push_back(test);
				}
			}
			isRepeat = false;
		}
		for (int k = 0; k < testCases.size(); k++) if (testCases[k].times == 0) counter++;
		if (counter == testCases.size()) {
			answer = i;
			break;
		}
		counter = 0;
		testCases.clear();
	}
	cout << endl << answer;
	fout << answer << '\n';

	return 0;
}