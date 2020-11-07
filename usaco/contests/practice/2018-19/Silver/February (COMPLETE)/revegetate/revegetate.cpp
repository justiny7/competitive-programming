// USACO Silver February 2019 Problem 3

#include <bits/stdc++.h>
using namespace std;

ifstream fin("revegetate.in");
ofstream fout("revegetate.out");

int n, m, groups[100001], type[100001];
vector<pair<int, char>> cows[100001];

void dfs(int cur, int lbl) {
	if (groups[cur] == lbl)
		return;
	groups[cur] = lbl;
	for (auto p : cows[cur])
		dfs(p.first, lbl);
}

int main(void) {
	fin >> n >> m;
	for (int i = 0; i < m; i++) {
		int a, b;
		char c;
		fin >> c >> a >> b;
		cows[a-1].push_back({b-1, c});
		cows[b-1].push_back({a-1, c});
	}
	fill(groups, groups+n, -1);
	int groupnum = 1;
	for (int i = 0; i < n; i++)
		if (groups[i] == -1)
			dfs(i, groupnum++);

	//for (int i = 0; i < n; i++)
	//	cout << groups[i] << " ";

	set<int> numgroups;
	fill(type, type+n, -1);
	for (int i = 0; i < n; i++) {
		if (type[i] >= 0)
			continue;
		numgroups.insert(groups[i]);
		queue<int> q;
		q.push(i);
		type[i] = 0;
		while (!q.empty()) {
			int t = q.front();
			q.pop();
			for (auto neigh : cows[t]) {
				if (type[neigh.first] == -1) {
					if (neigh.second == 'D')
						type[neigh.first] = (type[t]+1)%2;
					else
						type[neigh.first] = type[t];
					q.push(neigh.first);
				}
				else {
					if (neigh.second == 'D' && type[t] == type[neigh.first]) {
						fout << 0;
						return 0;
					}
					if (neigh.second == 'S' && type[t] != type[neigh.first]) {
						fout << 0;
						return 0;
					}
				}
			}
		}
	}


	fout << 1;
	int t = numgroups.size();
	while (t--)
		fout << 0;
	fout << '\n';

	return 0;
}