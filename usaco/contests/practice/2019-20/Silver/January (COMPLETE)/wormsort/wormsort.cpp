//USACO Silver January 2020 Problem 3

#include <bits/stdc++.h>
using namespace std;

//(When I realized my previous version had flaws that weren't caught by the test cases)
ifstream fin("wormsort.in");
ofstream fout("wormsort.out");

int n, m, outcount, cows[100001], groups[100001];
vector<vector<pair<int, int>>> wormholes;
vector<pair<int, int>> outoforder;

bool works(int minwidth) {
	fill(groups, groups+n, -1);
	int groupcount = 1;
	for (int i = 0; i < n; i++) {
		if (groups[i] > 0)
			continue;
		queue<int> q;
		q.push(i);
		while (!q.empty()) {
			int t = q.front();
			q.pop();
			groups[t] = groupcount;
			for (auto neigh : wormholes[t])
				if (neigh.first >= minwidth && groups[neigh.second] == -1) {
					groups[neigh.second] = -2;
					q.push(neigh.second);
				}
		}
		groupcount++;
	}

	for (int i = 0; i < outoforder.size(); i++)
		if (groups[outoforder[i].first] != groups[outoforder[i].second])
			return false;
	return true;
}

int main(void) {
	fin >> n >> m;
	for (int i = 0; i < n; i++) {
		fin >> cows[i];
		cows[i]--;
		if (cows[i] != i)
			outoforder.push_back({cows[i], i});
	}
	if (outoforder.size() == 0) {
		fout << -1 << '\n';
		return 0;
	}

	wormholes.resize(n);
	int largest = -1;
	for (int i = 0; i < m; i++) {
		int a, b, w;
		fin >> a >> b >> w;
		a--;
		b--;
		wormholes[a].push_back({w, b});
		wormholes[b].push_back({w, a});
		largest = max(largest, w);
	}

	//correct way w/ binary search
	int minwidth, lo = 1, hi = largest+1;
	while (lo < hi) {
		int mid = lo + (hi-lo)/2;
		//cout << mid << '\n';
		if (works(mid)) {
			minwidth = mid;
			lo = mid+1;
		}
		else
			hi = mid;
	}

	fout << minwidth << '\n';

	return 0;
}
