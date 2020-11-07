#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>

using namespace std;

ifstream fin("meetings.in");
ofstream fout("meetings.out");

int N, L;
vector<pair<int, pair<int, int>>> cows;
vector<int> lcows; //pos

int main(void) {
	fin >> N >> L;
	vector<pair<int, int>> tw;
	int totSum = 0; //total weight

	for (int i = 0; i < N; i++) {
		int x, w, d;
		fin >> w >> x >> d;
		cows.push_back({x, {w, d}});
		if (d == -1)
			lcows.push_back(x);
		totSum += w;
		//cout << cows[i].first << " " << cows[i].second.first << " " << cows[i].second.second << endl;
	}
	sort(cows.begin(), cows.end());
	vector<int> timeL, timeR;	

	for (int i = 0; i < N; i++) {
		if (cows[i].second.second == -1)
			timeL.push_back(cows[i].first);
		else timeR.push_back(L - cows[i].first);

	}
	reverse(timeR.begin(), timeR.end());

	for (int i = 0; i < timeL.size(); i++)
		tw.push_back({timeL[i], cows[i].second.first});
	for (int i = 0; i < timeR.size(); i++)
		tw.push_back({timeR[i], cows[N-i-1].second.first});
	sort(tw.begin(), tw.end());

	int T = 0, currSum = 0;
	while (currSum * 2 < totSum) {
		currSum += tw[T].second;
		T++;
	}
	T = tw[T-1].first;
	int meetings = 0;

	sort(lcows.begin(), lcows.end());
	for (int i = 0; i < cows.size(); i++) {
		if (cows[i].second.second == 1) {
			meetings += (upper_bound(lcows.begin(), lcows.end(), cows[i].first + T*2) - lower_bound(lcows.begin(), lcows.end(), cows[i].first));
		}
	}
	fout << meetings << endl;

	return 0;
}