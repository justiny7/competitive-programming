/*
ID: justiny7
LANG: C++
TASK: inflate
*/

//Unbounded knapsack problem (I think)
// (I learned this when searching up how to do knapsack for Subset Sums)

#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;

ifstream fin("inflate.in");
ofstream fout("inflate.out");

int m, n; //m = time bound
int points[10001], times[10001], dp[10001];

int main(void) {
	fin >> m >> n;
	for (int i = 0; i < n; i++)
		fin >> points[i] >> times[i];

	for (int i = 0; i <= m; i++) //Cycle through all times up until the max time (to set time boundaries)
		for (int j = 0; j < n; j++) //Cycle through how many problems there are
			if (times[j] <= i) //If the problem can fit within the current time bound
				dp[i] = max(dp[i], dp[i - times[j]] + points[j]); //The maximum for this time boundary is the max between the current time
																 //and (current time - time of this problem) + points this problem gives you

	fout << dp[m] << endl;

	return 0;
}