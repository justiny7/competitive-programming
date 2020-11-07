// USACO Silver February 2019 Problem 2

#include <bits/stdc++.h>
using namespace std;

ifstream fin("paintbarn.in");
ofstream fout("paintbarn.out");

int n, k, barn[1001][1001];

void paint(int x1, int y1, int x2, int y2) {
	for (int i = y1; i < y2; i++) {
		barn[i][x1]++; // add start
		barn[i][x2]--; // subtract start/add end
	}
}

int main(void) {
	fin >> n >> k;
	// record where paint starts and ends on each row, and count (how many starts)-(how many ends) and that's how many coats of paint are there
	for (int i = 0; i < n; i++) {
		int a, b, c, d;
		fin >> a >> b >> c >> d;
		paint(a, b, c, d);
	}

	int ans = 0;
	//forgot it could start at 0 smh
	for (int i = 0; i <= 1000; i++)
		for (int j = 0; j <= 1000; j++) {
			if (barn[i][j] == k)
				ans++;
			barn[i][j+1] += barn[i][j]; //either adds or removes starts
		}
	/*
	for (int i = 1; i <= 10; i++) {
		for (int j = 1; j <= 10; j++)
			cout << barn[i][j] << " ";
		cout << '\n';
	}*/

	fout << ans << '\n';
	return 0;
}