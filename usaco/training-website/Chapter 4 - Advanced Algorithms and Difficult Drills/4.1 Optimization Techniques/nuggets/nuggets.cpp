/*
ID: justiny7
LANG: C++
TASK: nuggets
*/

#include <bits/stdc++.h>
using namespace std;

ifstream fin("nuggets.in");
ofstream fout("nuggets.out");

int n, target, small;
vector<int> packages;
set<int> candidates;
bool odd;

bool multiple(int x) {
	for (int i = 0; i < packages.size(); i++)
		if (x%packages[i] == 0)
			return true;
	return false;
}

bool isdone() {
	int counter = 1, last;
	for (auto it = candidates.end(); it != candidates.begin(); it--) {
		if (it == candidates.end()) {
			last = *it;
			continue;
		}
		if (*it+1 == last)
			counter++;
		else
			counter = 1;
		if (counter == target) {
			small = *it;
			return true;
		}
		last = *it;
	}
	return false;
}

int main(void) {
	fin >> n;
	for (int i = 0; i < n; i++) {
		int b;
		fin >> b;
		if (!multiple(b)) {
			packages.push_back(b);
			if (b%2 != 0)
				odd = true;
		}
	}

	sort(packages.begin(), packages.end());
	if (packages[0] == 1 || !odd || packages.size() == 1) {
		fout << "0\n";
		return 0;
	}

	candidates.insert(0);
	target = packages[0];
	//find first sequence of packages[0] consecutive numbers
	while (1) {
		for (int i : packages) {
			int t = *candidates.begin();
			//cout << t << endl;
			candidates.insert(t+i);
		}

		if (isdone()) {
			fout << small - 1 << '\n';
			return 0;
		}

		candidates.erase(candidates.begin());
	}
	

	return 0;
}

/*
Retired recursive func (stack overflow)
bool done;

void solve() {
	for (int i : packages) {
		int t = *candidates.begin();
		//cout << t << endl;
		candidates.insert(t+i);
	}
	
	if (done)
		return;
	if (isdone()) {
		fout << small - 1 << '\n';
		done = true;
		return;
	}

	candidates.erase(candidates.begin());
	solve();
}
*/