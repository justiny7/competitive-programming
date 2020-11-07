//USACO 2018 December Contest Silver Problem One

#include <bits/stdc++.h>
#define BIG 2e9
using namespace std;

ifstream fin("convention.in");
ofstream fout("convention.out");

int n, m, c, ncount = 1, times[100001];

//Binary search for answer I think? If some max waiting time isn't possible, then all the ones smaller than it aren't either
bool canTake(int sec) {
	//Greedy method for seeing if min time of sec is possible
	int buses = 1, start = 0;
	for (int i = 1; i < n; i++) {
		if (times[i]-times[start] > sec || i-start == c) {
			buses++;
			start = i;
		}
		if (buses > m)
			return false;
	}
	//cout << start << '\n';
	return true;
}

//Bin search for answer
void binSearch() {
	int lo = 0, hi = 1e9;
	while (lo <= hi) {
		if (lo == hi)
			break;
		int mid = lo + (hi-lo)/2;
		if (canTake(mid))
			hi = mid;
		else
			lo = mid+1;
	}
	fout << lo << '\n';
}

int main(void) {
	fin >> n >> m >> c;
	for (int i = 0; i < n; i++)
		fin >> times[i];
	sort(times, times+n);

	for (int i = 1; i < n; i++) {
		if (times[i] != times[i-1])
			ncount++;
	}

	//Speical cases that don't require calculations
	if (ncount <= m || c == 1) {
		fout << "0\n";
		return 0;
	}
	if (m == 1) {
		fout << times[n-1] - times[0];
		return 0;
	}

	binSearch();

	return 0;
}