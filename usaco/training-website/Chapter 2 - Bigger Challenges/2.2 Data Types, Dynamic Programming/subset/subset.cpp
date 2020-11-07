/*
ID: justiny7
LANG: C++
TASK: subset
*/

#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>

using namespace std;

ifstream fin("subset.in");
ofstream fout("subset.out");

int N;
int ks[1000];

int main(void) {
	fin >> N;

	if ((N * (N + 1) / 2) % 2 != 0) {
		fout << "0\n";
		return 0;
	}
	int Target = N * (N + 1) / 4;

	ks[1] = 1;
	for (int i = 2; i <= N; i++)
		for (int j = Target; j > 0; j--)
			if (j - i > 0)
				ks[j] += ks[j - i];

	fout << ks[Target] << endl;

	return 0;
}