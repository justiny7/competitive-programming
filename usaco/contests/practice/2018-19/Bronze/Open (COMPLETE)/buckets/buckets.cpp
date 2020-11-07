//Bucket Brigade - USACO Open Bronze Problem

#include <iostream>
#include <fstream>
#include <stdlib.h>

using namespace std;

char map[10][10];
int Bx, By, Rx, Ry, Lx, Ly;

int main() {
	ofstream fout("buckets.out");
	ifstream fin("buckets.in");

	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			fin >> map[i][j];
			if (map[i][j] == 'B') {
				Bx = j;
				By = i;
			}
			else if (map[i][j] == 'R') {
				Rx = j;
				Ry = i;
			}
			else if (map[i][j] == 'L') {
				Lx = j;
				Ly = i;
			}
		}
	}
	cout << Bx << " " << By << endl << Rx << " " << Ry << endl << Lx << " " << Ly << endl;
	if (((Bx == Rx && Rx == Lx) && ((By < Ry && Ry < Ly) || (By > Ry && Ry > Ly))) || ((By == Ry && Ry == Ly) && ((Bx < Rx && Rx < Lx) || (Bx > Rx && Rx > Lx)))) {
		fout << abs(Bx - Lx) + abs(By - Ly) + 1;
	}
	else fout << abs(Bx - Lx) + abs(By - Ly) - 1;

	return 0;
}