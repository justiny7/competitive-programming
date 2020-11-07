/*
ID: justiny7
LANG: C++11
TASK: stamps
*/

#include <bits/stdc++.h>
using namespace std;

ifstream fin("stamps.in");
ofstream fout("stamps.out");

int k, n;
int stamps[51];
vector<int> nextStmps, currStmps;
bool marked[2000001];

int main(void) {
	fin >> k >> n;

	for (int i = 0; i < n; i++) {
		fin >> stamps[i];
		currStmps.push_back(stamps[i]);
		marked[stamps[i]] = true;
	}

	sort(stamps, stamps + n);
	
	//New idea: iterate through # of stamps that can be used, mark stamps already marked + each stamp value
	for (int i = 2; i <= k; i++) {
		for (int j : currStmps)
			for (int val = 0; val < n; val++) {
				if (!marked[j+stamps[val]]) {
					marked[j + stamps[val]] = true;
					nextStmps.push_back(j + stamps[val]);
					//cout << "Stmp at: " << j << "\tStmp val: " << stamps[val] << endl;
				}
			}

		//There's probably a more efficient way to do this...
		currStmps.clear();
		currStmps.reserve(nextStmps.size());
		copy(nextStmps.begin(), nextStmps.end(), back_inserter(currStmps));
		nextStmps.clear();
	}
	
	int counter;
	for (counter = 1; marked[counter]; counter++);

	fout << counter - 1 << endl;

	return 0;
}


/*	OLD IDEA THAT RAN TOO SLOW

const int BIG = 2e9;
bool done;
vector<int> stamps;
vector<int> counter(1000000); //counter[i] = min. # of stamps needed to make sum i

stamps.resize(n);
	for (int i = 0; i < n; i++)
		fin >> stamps[i];

	sort(stamps.begin(), stamps.end());



	counter[0] = 0; //0 stamps needed to make sum 0, if that's ever needed

	int i = 1;
	bool runThis;
	do {
		runThis = true;
		//find counter[i]
		counter[i] = BIG;
		for (int j = 0; j < n; j++) {
			if (i == stamps[j]) {
				counter[i] = 1;
				runThis = false;
				break;
			}
		}
		if (runThis) {
			for (int a = 0; a < i; a++) {
				/*cout << "i-a: " << i - a << "\ta: " << a << endl;
				cout << "counter[i-a]: " << counter[i - a] << "\tcounter[a]: " << counter[a] << endl;
				assert(i-a >= 0);
				assert(i - a <= i);
				
				counter[i] = min(counter[i], counter[i - a] + counter[a]);
				//Too slow - try the thing where if u hit max stamp, ur guaranteed to be able to
				//make all stamp values lower, so find some pattern for max (etc. try max stamp
				//val * tot stamps and count backward or smth like that)
			}
		}
		//cout << "i: " << i << "\tcount: " << counter[i] << endl;

	} while (counter[i++] <= k);

	fout << i - 2 << endl;



*/