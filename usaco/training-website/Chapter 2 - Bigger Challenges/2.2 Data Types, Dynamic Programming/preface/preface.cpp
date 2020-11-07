/*
ID: justiny7
LANG: C++
TASK: preface
*/

#include <iostream>
#include <vector>
#include <fstream>
#include <cmath>
#include <algorithm>

using namespace std;

ifstream fin("preface.in");
ofstream fout("preface.out");

char Numerals[7] = { 'I', 'V', 'X', 'L', 'C', 'D', 'M' };

int N;

vector<int> to_rom(int a) {
	vector<int> how_many(7);
	fill(how_many.begin(), how_many.end(), 0);

	for (int i = 1; i <= 4; i++) {
		int num = a % (int)pow(10, i);
		if (num <= 3*(int)pow(10, i-1))
			how_many[2*i - 2] += num / (int)pow(10, i-1);
		else if (num == 9 * (int)pow(10, i - 1)) {
			how_many[2 * i - 2] += 1;
			how_many[2 * i] += 1;
		}
		else {
			how_many[2*i-2] += abs(num - ((int)pow(10, i) / 2)) / (int)pow(10, i-1);
			how_many[2*i-1] += 1;
		}
		a -= num;
	}
	
	return how_many;
}

int main(void) {
	fin >> N;

	vector<int> ans (7);
	fill(ans.begin(), ans.end(), 0);
	for (int i = 1; i <= N; i++) {
		vector<int> temp = to_rom(i);
		for (int j = 0; j < 7; j++)
			ans[j] += temp[j];
	}

	for (int i = 0; i < 7; i++)
		if (ans[i] != 0)
			fout << Numerals[i] << " " << ans[i] << endl;


	return 0;
}