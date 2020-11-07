/*
ID: justiny7
LANG: C++
TASK: sprime
*/

#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

ifstream fin("sprime.in");
ofstream fout("sprime.out");
int N;

bool isPrime(int a) {
	if (a == 1) return false;
	if (a == 2 || a == 3) return true;
	if (a % 2 == 0) return false;
	for (int i = 3; i * i <= a; i += 2)
		if (a % i == 0) return false;
	return true;
}

// Find 1 digit primes, append 1-9, choose those that are still prime,
//append 1-9, repeat until length N is achieved
vector<int> answers;
void generate(int totDig, int curDig, int curNum) {
	if (curDig == totDig) {
		answers.push_back(curNum);
		return;
	}
	for (int i = 1; i < 10; i++) {
		curNum *= 10;
		curNum += i;
		if (isPrime(curNum))
			generate(totDig, curDig+1, curNum);
		curNum -= i;
		curNum /= 10;
	}
}

int main(void) {
	fin >> N;
	generate(N, 0, 0);
	sort(answers.begin(), answers.end());
	for (int i : answers)
		fout << i << endl;
	
	return 0;
}
