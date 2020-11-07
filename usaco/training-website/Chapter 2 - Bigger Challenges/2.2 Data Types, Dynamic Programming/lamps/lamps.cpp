/*
ID: justiny7
LANG: C++
TASK: lamps
*/

/*
	Probably the most repetitive (and therefore longest) code I've ever written fro USACO -_-
	The logic behind the code is simple, but I'm sure there are many more ways to code this more efficient
		**cough cough probably a good time to start learning how to use bits and stuff**

	Basically worked on the first try though (third try because I forgot to include the C = 0 case haha)
*/

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

ifstream fin("lamps.in");
ofstream fout("lamps.out");

//Flips all lamps
vector<bool> button1(vector<bool> lmps) {
	for (int i = 0; i < lmps.size(); i++)
		lmps[i] = !lmps[i];
	return lmps;
}

//Flips odd lamps
vector<bool> button2(vector<bool> lmps) {
	for (int i = 0; i < lmps.size(); i++)
		if (i % 2 == 0)
			lmps[i] = !lmps[i];
	return lmps;
}

//Flips even lamps
vector<bool> button3(vector<bool> lmps) {
	for (int i = 0; i < lmps.size(); i++)
		if (i % 2 == 1)
			lmps[i] = !lmps[i];
	return lmps;
}

//Flips lamps 1, 4, 7, ...
vector<bool> button4(vector<bool> lmps) {
	for (int i = 0; i < lmps.size(); i++)
		if (i % 3 == 0)
			lmps[i] = !lmps[i];
	return lmps;
}

vector<bool> flip(string sequence, vector<bool> a) {
	if (sequence[0] == '1')
		a = button1(a);
	if (sequence[1] == '1')
		a = button2(a);
	if (sequence[2] == '1')
		a = button3(a);
	if (sequence[3] == '1')
		a = button4(a);

	return a;
}

int N, C;
bool yes = false;
vector<int> on, off;
vector<vector<bool>> answers;

//Reads input
void readInput() {
	int temp;
	do {
		fin >> temp;
		on.push_back(temp);
	} while (temp != -1);
	on.pop_back();
	do {
		fin >> temp;
		off.push_back(temp);
	} while (temp != -1);
	off.pop_back();
}

//See if this pattern meets the given conditions
bool works(vector<bool> config) {
	for (int i : on)
		if (config[i-1] != 1)
			return false;
	for (int i : off)
		if (config[i-1] != 0)
			return false;
	yes = true;
	return true;
}

//Tests if flipping x of the 4 buttons works
void test0of4(vector<bool> lps) {
	if (works(lps))
		answers.push_back(lps);
}

void test1of4(vector<bool> lps) {
	vector<bool>test;
	for (int i = 0; i < 4; i++) {
		string seq = "0000";
		seq[i] = '1';
		//cout << seq << endl;
		test = flip(seq, lps);
		if (works(test))
			answers.push_back(test);
	}
}

void test2of4(vector<bool> lps) {
	vector<bool>test;
	for (int i = 0; i < 3; i++) {
		for (int j = i + 1; j < 4; j++) {
			string seq = "0000";
			seq[i] = '1';
			seq[j] = '1';
			//cout << seq << endl;
			test = flip(seq, lps);
			if (works(test))
				answers.push_back(test);
		}
	}
}

void test3of4(vector<bool> lps) {
	vector<bool>test;
	for (int i = 0; i < 4; i++) {
		string seq = "1111";
		seq[i] = '0';
		//cout << seq << endl;
		test = flip(seq, lps);
		if (works(test))
			answers.push_back(test);
	}
}

void test4of4(vector<bool> lps) {
	vector<bool>test;
	test = flip("1111", lps);
	if (works(test))
		answers.push_back(test);
}

//Tests all possible combinations of flips based on C
void test(vector<bool> lps) {
	if (C == 0)
		test0of4(lps);
	else if (C == 1)
		test1of4(lps);
	else if (C == 2) {
		test0of4(lps);
		test2of4(lps);
	}
	else if (C % 2 == 1) {
		test1of4(lps);
		test3of4(lps);
	}
	else {
		test0of4(lps);
		test2of4(lps);
		test4of4(lps);
	}
}


int main(void) {
	fin >> N >> C;
	readInput();
	
	vector<bool> lamps(N);
	fill(lamps.begin(), lamps.end(), 1);

	test(lamps);
	if (!yes)
		fout << "IMPOSSIBLE\n";
	else {
		sort(answers.begin(), answers.end());
		for (int i = 0; i < answers.size(); i++) {
			for (int j = 0; j < N; j++)
				fout << answers[i][j];
			fout << endl;
		}
	}

	return 0;
}