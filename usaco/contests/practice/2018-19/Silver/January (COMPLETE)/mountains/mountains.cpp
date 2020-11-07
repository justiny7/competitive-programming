// USACO Silver Jaunary 2019 Problem 3

#include <bits/stdc++.h>
using namespace std;

//Idea - a mountain is indistinguishable if its base lies within another mountain's base
ifstream fin("mountains.in");
ofstream fout("mountains.out");

int n;
vector<pair<int, int>> mountains;

int main(void) {
	fin >> n;
	for (int i = 0; i < n; i++) {
		int x, y;
		fin >> x >> y;
		mountains.push_back({x-y, x+y});
	}
	sort(mountains.begin(), mountains.end());
	int distinct = 1, rightmost = mountains[0].second; //keep track of rightmost point
	for (int i = 1; i < n; i++) {
		if (mountains[i].second > rightmost) {
			distinct++;
			rightmost = mountains[i].second;
			if (mountains[i].first == mountains[i-1].first) //if mountains start in same place, then they're guaranteed to not be distinct
				distinct--;
		}
	}

	fout << distinct << '\n';

	return 0;
}
