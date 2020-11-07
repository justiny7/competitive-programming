//USACO Silver December 2018 Problem 2

#include <bits/stdc++.h>
using namespace std;

ifstream fin("convention2.in");
ofstream fout("convention2.out");

int n;
vector<pair<int, pair<int, int>>> cows; //arrival time, seniority, eating time
bool waiting[100001];

bool waitMethod(pair<int, pair<int, int>> a, pair<int, pair<int, int>> b) {
	return (a.second.first < b.second.first);
}

int main(void) {
	fin >> n;
	for (int i = 1; i <= n; i++) {
		int a, b;
		fin >> a >> b;
		cows.push_back({a, {i, b}});
	}
	sort(cows.begin(), cows.end());

	int ans = 0, curtime = cows[0].first;
	for (int i = 0; i < n; i++) {
		int endtime, curwait = 0;
		if (waiting[i])
			curwait = curtime - cows[i].first;
		else
			curtime = cows[i].first;
		endtime = curtime + cows[i].second.second;
		//cout << "endtime: " << endtime << '\n';
		ans = max(ans, curwait);
		for (int j = i+1; j < n; j++) {
			if (cows[j].first <= endtime)
				waiting[j] = true;
			else {
				sort(cows.begin()+i+1, cows.begin()+j, waitMethod);
				break;
			}
		}
		curtime = endtime;
	}
	fout << ans << '\n';

	return 0;
}