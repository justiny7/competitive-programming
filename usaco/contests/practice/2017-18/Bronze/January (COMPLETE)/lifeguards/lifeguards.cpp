//USACO Bronze January 2018 Problem 2

#include <bits/stdc++.h>
using namespace std;

ifstream fin("lifeguards.in");
ofstream fout("lifeguards.out");

int n;
pair<int, int> cows[101];

int main(void) {
	fin >> n;
	for (int i = 0; i < n; i++)
		fin >> cows[i].first >> cows[i].second;

	int ans = 0;
	for (int i = 0; i < n; i++) {
		bool times[1001];
		fill(times, times+1001, false);
		for (int j = 0; j < n; j++) {
			if (j == i)
				continue;
			for (int t = cows[j].first; t < cows[j].second; t++)
				times[t] = true;
		}
		int counter = 0;
		for (int t = 0; t < 1001; t++)
			if (times[t])
				counter++;
		ans = max(ans, counter);
	}

	fout << ans << '\n';

	return 0;
}
