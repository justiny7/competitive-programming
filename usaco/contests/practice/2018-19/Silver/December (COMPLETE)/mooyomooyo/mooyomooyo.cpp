//USACO Silver December 2018 Problem 3

#include <bits/stdc++.h>
using namespace std;

ifstream fin("mooyomooyo.in");
ofstream fout("mooyomooyo.out");

int n, k, game[100][10];

void print() {
	for (int i = n-1; i >= 0; i--) {
		for (int j = 0; j < 10; j++)
			fout << game[i][j];
		fout << '\n';
	}
}

bool delHay(int starty, int startx) {
	if (game[starty][startx] == 0)
		return false;

	int visited[100][10];
	for (int i = 0; i < n; i++)
		fill(visited[i], visited[i]+10, -1);

	queue<pair<int, int>> q;
	vector<pair<int, int>> candidates;
	bool found = false;
	int cursect = 0;
	q.push({starty, startx});
	while (!q.empty()) {
		int y = q.front().first, x = q.front().second;
		q.pop();
		if (visited[y][x] < 0) {
			//cout << y << ", " << x << '\n';
			candidates.push_back({y, x});
			visited[y][x] = 0;
			cursect++;
		
			int target = game[y][x];
			if (y > 0 && game[y-1][x] == target && visited[y-1][x] == -1) {
				visited[y-1][x] = -2;
				q.push({y-1, x});
			}
			if (y < n-1 && game[y+1][x] == target && visited[y+1][x] == -1) {
				visited[y+1][x] = -2;
				q.push({y+1, x});
			}
			if (x > 0 && game[y][x-1] == target && visited[y][x-1] == -1) {
				visited[y][x-1] = -2;
				q.push({y, x-1});
			}
			if (x < 9 && game[y][x+1] == target && visited[y][x+1] == -1) {
				visited[y][x+1] = -2;
				q.push({y, x+1});
			}
		}
	}
	if (cursect >= k) {
		for (auto p : candidates)
			game[p.first][p.second] = 0;
		return true;
	}
	return false;
}

bool stillHas() {
	bool yes = false;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < 10; j++)
			if (delHay(i, j))
				yes = true;
	return yes;
}

void shift() {
	for (int i = 0; i < 10; i++) {
		vector<int> column;
		for (int j = 0; j < n; j++)
			if (game[j][i] > 0)
				column.push_back(game[j][i]);
		for (int j = 0; j < n; j++) {
			if (j < column.size())
				game[j][i] = column[j];
			else
				game[j][i] = 0;
		}
	}
}

int main(void) {
	fin >> n >> k;
	for (int i = n-1; i >= 0; i--)
		for (int j = 0; j < 10; j++) {
			char a;
			fin >> a;
			game[i][j] = a - '0';
		}

	do {
		shift();
	} while (stillHas());
	print();

	return 0;
}