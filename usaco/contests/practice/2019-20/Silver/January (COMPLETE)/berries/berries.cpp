// USACO Silver January 2020 Problem 1

//Bin search for ans - once you can't get a certain # of berries, you can't get any more than that
//Nope wrong approach - doesn't consider remainders
#include <bits/stdc++.h>
using namespace std;

ifstream fin("berries.in");
ofstream fout("berries.out");

int n, k, berries[1001], biggest = -1;


int main(void) {
	fin >> n >> k;
	for (int i = 0; i < n; i++){
		fin >> berries[i];
		biggest = max(biggest, berries[i]);
	}

	int ans = 0;
	for (int i = 1; i <= biggest; i++) {
		int sections[1001], curberries = 0, curgiven = 0, cursect = i;
		fill(sections, sections+1001, 0);
		for (int j = 0; j < n; j++) {
			sections[i] += berries[j]/i;
			sections[berries[j]%i]++;
		}
		sections[i] -= k/2;
		if (sections[i] < 0)
			continue;
		while (curgiven < k/2 && cursect > 0) {
			if (sections[cursect] > 0) {
				sections[cursect]--;
				curgiven++;
				curberries += cursect;
			}
			else
				cursect--;
		}
		if (curgiven < k/2)
			continue;
		//cout << i << " " << curberries << '\n';
		ans = max(ans, curberries);
	}

	fout << ans << '\n';

	return 0;
}