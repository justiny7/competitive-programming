/*
ID: justiny7
LANG: C++
TASK: pprime
*/

#include <iostream>
#include <fstream>
#include <cmath>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

ifstream fin("pprime.in");
ofstream fout("pprime.out");

int A, B;
vector<int> pals;
vector<vector<int>> test(4); //half pals of 4 lengths
int starts[4] = { 1, 3, 7, 9 };

void recursePrint(int N, int start, int currSum) { //Generates all candidates to be flipped into a palindrome
	if (N == -1) {
		//cout << currSum << endl;
		test[start].push_back(currSum);
		return;
	}
	if (N == start)
		for (int i = 0; i < 4; i++) {
			currSum += starts[i] * pow(10, N);
			recursePrint(N - 1, start, currSum);
			currSum -= starts[i] * pow(10, N);
		}
	else
		for (int i = 0; i < 10; i++) {
			currSum += i * pow(10, N);
			recursePrint(N - 1, start, currSum);
			currSum -= i * pow(10, N);
		}
}

void flipIntoPals(vector<vector<int>> a) { //Flips all of the numbers generated in function above into a palindrome
	for (int i = 0; i < 8; i++) {
		vector<int> tempVec;
		for (int j = 0; j < a[i/2].size(); j++) {
			string temp = to_string(a[i/2][j]);
			string temp2;
			if (i % 2 != 0) temp2 = temp;
			else temp2.append(temp.begin(), temp.end() - 1);
			reverse(temp2.begin(), temp2.end());
			temp.append(temp2);
			pals.push_back(stoi(temp));
		}
	}
}

bool isPrime(int a) {
	for (int i = 2; i <= sqrt(a); i++)
		if (a % i == 0)
			return false;
	return true;
}

int main(void) {
	fin >> A >> B;
	recursePrint(0, 0, 0);
	recursePrint(1, 1, 0);
	recursePrint(2, 2, 0);
	recursePrint(3, 3, 0);
	flipIntoPals(test);

	int lowestPal = lower_bound(pals.begin(), pals.end(), A) - pals.begin(); // (indexes)
	int largestPal = upper_bound(pals.begin(), pals.end(), B) - pals.begin();

	if (A == 5) fout << 5 << endl;

	for (int i = lowestPal; i < largestPal; i++) {
		if (isPrime(pals[i])) fout << pals[i] << endl;
	}
	return 0;
}