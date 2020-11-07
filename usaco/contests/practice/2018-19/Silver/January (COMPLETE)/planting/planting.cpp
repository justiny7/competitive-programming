// USACO Silver January 2019 Problem 1

//Bruh
#include <bits/stdc++.h>
using namespace std;

ifstream fin("planting.in");
ofstream fout("planting.out");

int n, ans, groups[100001];
//pair<vector<int>, vector<int>> adjList[100001];

int main(void) {
	fin >> n;

	//No way this can work...
	for (int i = 1; i < n; i++) {
		int a, b;
		fin >> a >> b;
		groups[a]++; //computing neighbors of each node, b/c the area around each section has N+1 nodes, so find the largest
		groups[b]++;//section + 1 and that's the answer???? Seems unlikely but it's worth a go
	}
	for (int i = 1; i <= n; i++)
		ans = max(ans, groups[i]);
	fout << ans+1 << '\n';
	//fout << ans << '\n';

	return 0;
}

//Old code
/*
	for (int i = 1; i <= n-1; i++) {
		int a, b;
		fin >> a >> b;
		adjList[a].first.push_back(b);
		adjList[b].first.push_back(a);
		groups[i] = -1;
	}
	groups[n] = -1;

	queue<int> q;
	q.push(1);
	while (!q.empty()) {
		int t = q.front(), cur;
		//cout << t<<'\n';
		q.pop();
		bool vis[100002];
		fill(vis, vis+n, false);
		for (int neigh : adjList[t].first) {
			if (groups[neigh] > 0 && !vis[groups[neigh]]) {
				vis[groups[neigh]] = true;
				adjList[t].second.push_back(neigh);
				adjList[neigh].second.push_back(t);
				for (int neigh2 : adjList[neigh].second) {
					if (neigh2 != t) {
						//cout << "neigh2: " << groups[neigh2] << '\n';
						vis[groups[neigh2]] = true;
					}
				}
			}
			else if (groups[neigh] == -1) {
				q.push(neigh);
				groups[neigh] = -2;
			}
		}
		for (cur = 1; vis[cur]; cur++);
		groups[t] = cur;
		ans = max(ans, cur);
	}*/

	/*
	for (int i = 1; i <= n; i++)
		cout << groups[i] << " ";
	cout << '\n';*/