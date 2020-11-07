/*
ID: justiny7
LANG: C++
TASK: zerosum
*/

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <cmath>

using namespace std;

int N;
vector<string> testCases;
char chars[] = " +-";

ifstream fin("zerosum.in");
ofstream fout("zerosum.out");

//Checks if it can sum to 0 with a string of '+', '-', or ' '
bool check(string seq) {
	int sum = 0;
	int cur = N;
	int tenCnt = 0;
	for (int i = N-2; i >= 0; i--) {
		switch (seq[i])
		{
		case '+':
			sum += cur;
			cur = i + 1;
			tenCnt = 0;
			break;
		case '-':
			sum -= cur;
			cur = i + 1;
			tenCnt = 0;
			break;
		default:
			tenCnt++;
			cur += pow(10, tenCnt) * (i+1);
			break;
		}
	}
	sum += cur;
	return (sum == 0);
}

//Generates strings of length N into testCases in ASCII order
void genStrings(string curStr) {
	if (curStr.length() == N-1) {
		testCases.push_back(curStr);
		return;
	}
	for (int i = 0; i < 3; i++) {
		curStr.push_back(chars[i]);
		genStrings(curStr);
		curStr.pop_back();
	}
}

//Prints in correct format
void print(string a) {
	for (int i = 1; i <= N; i++) {
		fout << i;
		if (i != N)
			fout << a[i-1];
	}
	fout << endl;
}

int main(void) {
	fin >> N;
	genStrings("");

	for (string i : testCases)
		if (check(i))
			print(i);

	return 0;
}