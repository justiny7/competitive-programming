// USACO Silver February 2019 Problem 1

#include <bits/stdc++.h>
using namespace std;

ifstream fin("herding.in");
ofstream fout("herding.out");

int n, gap1, gap2, biggest, smallest = 2e9, consec = 1;
vector<int> cows;

int main(void) {
	fin >> n;
	cows.resize(n);
	for (int i = 0; i < n; i++)
		fin >> cows[i];
	sort(cows.begin(), cows.end());
	int maxconsec = 1, lgap = 0;
	for (int i = 1; i < n; i++) {
		if (cows[i]-cows[i-1] == 1)
			consec++;
		else {
			maxconsec = max(consec, maxconsec);
			consec = 1;
		}
		lgap = max(lgap, cows[i]-cows[i-1]-1);
		if (i < n-1)
			gap1 += cows[i]-cows[i-1]-1;
		if (i > 1)
			gap2 += cows[i]-cows[i-1]-1;
	}

	if (maxconsec == n) {
		fout << 0 << '\n' << 0 << '\n';
		return 0;
	}

	biggest = max(gap1, gap2); //biggest is max of gaps excluding first one/gaps excluding last one b/c you can fill all gaps in between I think
	if (n == 3)
		smallest = min(min(gap1, gap2), 2);
	else if (maxconsec == n-1)
		smallest = min(2, lgap);
	else { //window of n sections - min is min of (n - occupied spaces in window, curmin)
		for (int i = 0; i < n; i++) {
			int ending = cows[i]+n-1, numgaps;
			if (ending <= cows[n-1])
				numgaps = n - (upper_bound(cows.begin()+i, cows.end(), ending)-(cows.begin()+i));
			else
				break;
			smallest = min(smallest, numgaps);
		}
	}


	fout << smallest << '\n' << biggest << '\n';

	return 0;
}