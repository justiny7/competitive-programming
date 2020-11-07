//USACO Silver January 2020 Problem 3

//Buggy Version
#include <bits/stdc++.h>
using namespace std;

ifstream fin("wormsort.in");
ofstream fout("wormsort.out");

int n, m, outcount, cows[100001], groups[100001], grpcount[100001];
vector<pair<int, pair<int, int>>> wormholes;
bool outoforder[100001];

int main(void) {
	fin >> n >> m;
	for (int i = 0; i < n; i++) {
		fin >> cows[i];
		cows[i]--;
		if (cows[i] != i) {
			outoforder[i] = true;
			outcount++;
		}
	}
	if (outcount == 0) {
		fout << -1 << '\n';
		return 0;
	}

	for (int i = 0; i < m; i++) {
		int a, b, w;
		fin >> a >> b >> w;
		a--;
		b--;
		wormholes.push_back({w, {a, b}});
	}

	sort(wormholes.begin(), wormholes.end());
	fill(groups, groups+n, -1);

	int minwidth = 2e9, cur = m-1, groupcount = 1, lgroup = -1;

	//lgroup is largest group, but we only count the wormholes that are out of order
	while (lgroup < outcount && cur >= 0) { //Cycle from largest-width wormhole to 0
		int st = wormholes[cur].second.first, fi = wormholes[cur].second.second;
		if (groups[st] == -1 && groups[fi] == -1) { //If both are unvisited, create new group
			groups[st] = groups[fi] = groupcount;
			if (outoforder[st] && outoforder[fi]) {
				grpcount[groupcount] += 2;
				lgroup = max(lgroup, 2);
			}
			else if (outoforder[st] ^ outoforder[fi]) { //could've used normal OR here but cuz it's already not AND but I felt extra xd
				grpcount[groupcount]++;
				lgroup = max(lgroup, 1);
			}
			groupcount++;
		}
		else if ((groups[st] == -1) ^ (groups[fi] == -1)) { //same here lol (if only one is unvisited, add that to visited group)
			if (groups[st] == -1) {
				grpcount[groups[st]]--;
				groups[st] = groups[fi];
				if (outoforder[st])
					grpcount[groups[st]]++;
			}
			else {
				grpcount[groups[fi]]--;
				groups[fi] = groups[st];
				if (outoforder[fi])
					grpcount[groups[st]]++;
			}
			lgroup = max(lgroup, grpcount[groups[st]]);
		}
		else if (groups[st] != groups[fi]) { //If both are visited and they're in different groups, put all of group 1 into group 2
			int target = groups[st];
			grpcount[groups[fi]] += grpcount[target];
			grpcount[target] = 0; //unnecessary - this group doesn't exist anymore, so it's grpcount won't ever be accessed
			for (int i = 0; i < n; i++)
				if (groups[i] == target)
					groups[i] = groups[fi];
			lgroup = max(lgroup, grpcount[groups[fi]]);
		}
		//cout << lgroup << '\n';

		minwidth = wormholes[cur].first;
		cur--;
	}

	fout << minwidth << '\n';

	return 0;
}