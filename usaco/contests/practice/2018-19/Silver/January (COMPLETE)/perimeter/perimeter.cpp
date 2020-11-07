//USACO Silver January 2019 Problem 2

#include <bits/stdc++.h>
using namespace std;

ifstream fin("perimeter.in");
ofstream fout("perimeter.out");

int n, maxper = 2e9, maxa, cream[1001][1001];

int main(void) {
	fin >> n;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++) {
			char a;
			fin >> a;
			if (a == '#')
				cream[i][j] = -1;
			else
				cream[i][j] = -5;
		}

	int groupcount = 1;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++) {
			if (cream[i][j] > 0 || cream[i][j] == -5)
				continue;
			int curper = 0, cursize = 0;
			queue<pair<int, int>> q;
			q.push({i, j});
			while (!q.empty()) {
				cursize++;
				int y = q.front().first, x = q.front().second;
				q.pop();
				cream[y][x] = groupcount;
				if (y > 0 && cream[y-1][x] == -1) {
					cream[y-1][x] = -2;
					q.push({y-1, x});
				}
				else if (y == 0 || cream[y-1][x] == -5)
					curper++;
				if (y < n-1 && cream[y+1][x] == -1) {
					cream[y+1][x] = -2;
					q.push({y+1, x});
				}
				else if (y == n-1 || cream[y+1][x] == -5)
					curper++;
				if (x > 0 && cream[y][x-1] == -1) {
					cream[y][x-1] = -2;
					q.push({y, x-1});
				}
				else if (x == 0 || cream[y][x-1] == -5)
					curper++;
				if (x < n-1 && cream[y][x+1] == -1) {
					cream[y][x+1] = -2;
					q.push({y, x+1});
				}
				else if (x == n-1 || cream[y][x+1] == -5)
					curper++;
			}
			groupcount++;
			if (cursize >= maxa) {
				if (cursize == maxa)
					maxper = min(maxper, curper);
				else
					maxper = curper;
				maxa = cursize;
			}
		}
	/*
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++)
			cout << cream[i][j] << " ";
		cout << '\n';
	}*/

	fout << maxa << " " << maxper << '\n';

	return 0;
}