/*
ID: justiny7
LANG: C++
TASK: frac1
*/

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

ifstream fin("frac1.in");
ofstream fout("frac1.out");

int N;
vector<pair<double, pair<int, int>>> fracs; //value, num, den

void fillFracs(int maxDen, int curDen) {
	if (curDen == maxDen + 1) return;

	for (int i = 1; i < curDen; i++) {
		fracs.push_back({ (double)i / curDen,{i,curDen} });
	}
	fillFracs(maxDen, curDen + 1);
}

int main(void) {
	fin >> N;
	
	fillFracs(N, 1);
	sort(fracs.begin(), fracs.end());

	fout << "0/1\n";

	for (int i = 0; i < fracs.size(); i++) {
		if ((i == 0) || (i != 0 && fracs[i].first != fracs[i - 1].first))
			fout << fracs[i].second.first << "/" << fracs[i].second.second << endl;
	}

	fout << "1/1\n";

	return 0;
}