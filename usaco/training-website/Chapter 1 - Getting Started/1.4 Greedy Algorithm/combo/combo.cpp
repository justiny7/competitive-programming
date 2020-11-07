/*
ID: justiny7
LANG: C++
TASK: combo
*/

//USACO Past Problem - Combo Locks, also training website problem xp

#include <iostream>
#include <fstream>
#include <stdlib.h>

using namespace std;

int N;
int john[3];
int maker[3];
int counter = 0;

int main() {
	ofstream fout("combo.out");
	ifstream fin("combo.in");

	fin >> N;
	cout << N << "\n\n";

	for (int i = 0; i < 3; i++) { fin >> john[i]; cout << john[i] << " "; } cout << endl;
	for (int i = 0; i < 3; i++) { fin >> maker[i]; cout << maker[i] << " "; }
	cout << "\n\n";
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			for (int k = 1; k <= N; k++) { //quite possible the largest if statement I have ever wrote in my life thus far (11/12/19)
				if ((((abs(i - john[0]) <= 2) || ((john[0] + N - i) <= 2) || (john[0] == N && (i == 1 || i == 2)) || ((john[0] == (N - 1)) && i == 1)) &&
						((abs(j - john[1]) <= 2) || ((john[1] + N - j) <= 2) || (john[1] == N && (j == 1 || j == 2)) || ((john[1] == (N - 1)) && j == 1)) &&
						((abs(k - john[2]) <= 2) || ((john[2] + N - k) <= 2) || (john[2] == N && (k == 1 || k == 2)) || ((john[2] == (N - 1)) && k == 1))) ||
						(((abs(i - maker[0]) <= 2) || ((maker[0] + N - i) <= 2) || (maker[0] == N && (i == 1 || i == 2)) || ((maker[0] == (N - 1)) && i == 1)) &&
						((abs(j - maker[1]) <= 2) || ((maker[1] + N - j) <= 2) || (maker[1] == N && (j == 1 || j == 2)) || ((maker[1] == (N - 1)) && j == 1)) &&
						((abs(k - maker[2]) <= 2) || ((maker[2] + N - k) <= 2) || (maker[2] == N && (k == 1 || k == 2)) || ((maker[2] == (N - 1)) && k == 1)))) {
					cout << i << " " << j << " " << k << endl;
					counter++;
				}
			}
		}
	}

	fout << counter << '\n';
	cout << counter << endl;

	return 0;
}

