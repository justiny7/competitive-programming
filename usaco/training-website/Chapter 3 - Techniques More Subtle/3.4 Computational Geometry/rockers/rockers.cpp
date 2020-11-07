/*
ID: justiny7
LANG: C++
TASK: rockers
*/

#include <bits/stdc++.h>
using namespace std;

ifstream fin("rockers.in");
ofstream fout("rockers.out");

int n, t, m, mintime = 1e9, most;
int songs[21];

//record max of taking/not taking this disc
void recurse(int disc, int cursum, int left, int dleft) {
	if (disc == n || (dleft == 0 && left < mintime)) {
		most = max(most, cursum);
		return;
	}
	
	if (songs[disc] <= left && dleft >= 0) { //if song can fit on disc..
		recurse(disc+1, cursum+1, left-songs[disc], dleft); //put it on disc
		recurse(disc+1, cursum, left, dleft); //don't put it on disc
	}
	else if (songs[disc] > left) { //if song can't fit on disc..
		if (left < mintime && dleft > 0) //if there isn't any more time left on this disc but there are still more disks left
			recurse(disc, cursum, t, dleft-1); //move onto next disc
		else { //there's still time left on disc
			recurse(disc+1, cursum, left, dleft); //move onto next song
			if (dleft > 0)
				recurse(disc, cursum, t, dleft-1); //move onto next disc
		}
	}
}

int main(void) {
	fin >> n >> t >> m;
	for (int i = 0; i < n; i++) {
		fin >> songs[i];
		mintime = min(songs[i], mintime);
	}

	recurse(0, 0, t, m-1);
	fout << most << '\n';

	return 0;
}