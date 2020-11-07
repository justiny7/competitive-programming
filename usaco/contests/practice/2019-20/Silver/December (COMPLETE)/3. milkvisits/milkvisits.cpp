//USACO Silver December 2019 Problem 3

#include <bits/stdc++.h>
using namespace std;

ifstream fin("milkvisits.in");
ofstream fout("milkvisits.out");

int n, m, groups[100001];
string types;
vector<vector<int>> adjList;

int main(void) {
	fin >> n >> m >> types;
	adjList.resize(n);
	for (int i = 1; i < n; i++) {
		int a, b;
		fin >> a >> b;
		adjList[a-1].push_back(b-1);
		adjList[b-1].push_back(a-1);
	}

	//finding paths with only G's or H's
	int counter = 1;
	fill(groups, groups+n, -1);
	for (int i = 0; i < n; i++) {
		if (groups[i] > 0)
			continue;
		queue<int> q;
		q.push(i);
		while (!q.empty()) {
			int t = q.front();
			q.pop();
			groups[t] = counter;
			for (int neigh : adjList[t])
				if (types[neigh] == types[t] && groups[neigh] == -1) {
					groups[neigh] = -2;
					q.push(neigh);
				}
		}
		counter++;
	}

	//for (int i = 0; i < n; i++)
	//	cout << groups[i] << " ";

	for (int i = 0; i < m; i++) {
		int st, fi;
		char type;
		fin >> st >> fi >> type;
		st--;
		fi--;

		if (types[st] == type || types[fi] == type)
			fout << 1;
		else {
			//Looks if start and finish are on an all-H or all-G path
			bool done = false;
			if (type == 'G' && groups[st] == groups[fi] && types[st] == 'H')
				fout << 0;
			else if (type == 'H' && groups[st] == groups[fi] && types[st] == 'G')
				fout << 0;
			else
				fout << 1;
		}
	}
	fout << '\n';

	return 0;
}