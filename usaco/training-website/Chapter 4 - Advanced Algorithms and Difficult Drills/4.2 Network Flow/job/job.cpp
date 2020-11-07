/*
ID: justiny7
LANG: C++
TASK: job
*/

//It took too long to think of this solution =_=
#include <bits/stdc++.h>
#define BIG 2e9
using namespace std;

ifstream fin("job.in");
ofstream fout("job.out");

int n, a, b, Atimes[201], Btimes[201];

int main(void) {
	fin >> n >> a >> b;
	for (int i = 0; i < a; i++)
		fin >> Atimes[i];
	for (int i = 0; i < b; i++)
		fin >> Btimes[i];

	sort(Atimes, Atimes+a);
	sort(Btimes, Btimes+b);
	
	//Greedy method for finding fastest time of each job for machine A
	int Aans = 0, Aavail[201], Afinish[1001];
	fill(Aavail, Aavail+a, 0);
	for (int i = 0; i < n; i++) {
		Afinish[i] = BIG;
		int temp;
		for (int j = 0; j < a; j++) {
			if (Aavail[j] + Atimes[j] < Afinish[i]) {
				temp = j;
				Afinish[i] = Aavail[j] + Atimes[j];
			}
		}
		Aavail[temp] += Atimes[temp];
		Aans = max(Aans, Afinish[i]);
	}

	//Same method for finding fastest time of each job for machine B
	int Bavail[201], Bfinish[1001];
	fill(Bavail, Bavail+b, 0);
	for (int i = 0; i < n; i++) {
		Bfinish[i] = BIG;
		int temp;
		for (int j = 0; j < b; j++) {
			if (Bavail[j] + Btimes[j] < Bfinish[i]) {
				temp = j;
				Bfinish[i] = Bavail[j] + Btimes[j];
			}
		}
		Bavail[temp] += Btimes[temp];
	}

	//Now, we work backwards, pairing the fastest times of machine A with the slowest times for machine B
	sort(Afinish, Afinish+n);
	sort(Bfinish, Bfinish+n);
	int Bans = 0;
	for (int i = 0; i < n; i++)
		Bans = max(Bans, Afinish[i] + Bfinish[n-1-i]);

	fout << Aans << " " << Bans << '\n';

	return 0;
}