/*
ID: justiny7
LANG: C++
TASK: hamming
*/

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <cmath>

using namespace std;

ifstream fin("hamming.in");
ofstream fout("hamming.out");

int N, B, D;  //N = # of codewords, B = # of bits in each codeword, D = Hamming distance

string to_bin(int n, int len) { //Converts int to binary string
	string ans = "";
	int i = 0;
	while (n > 0) {
		ans.insert(0, to_string(n % 2));
		n /= 2;
		i++;
	}
	while (ans.length() <= len)
		ans.insert(0, "0");
	return ans;
}

int Hamming(string a, string b) { //Finds the Hamming distance of two binary strings
	int n = a.length();
	int count = 0;
	for (int i = 0; i < n; i++)
		if (a[i] != b[i])
			count++;
	return count;
}

int main(void) {
	fin >> N >> B >> D;

	vector<string> last;
	last.push_back(to_bin(0, B));
	fout << "0";
	for (int i = 1; i < pow(2, B); i++) { //Cycles from 1 to 2^B (B <= 8)
		int counter = 0;
		for (int j = 0; j < last.size(); j++) { //Cycles through all previous approved numbers to check Hamming distance with each
			if (Hamming(to_bin(i, B), last[j]) >= D)
				counter++;
		}
		if (counter == last.size()) { //Printing mechanism
			last.push_back(to_bin(i, B));
			if (last.size() % 10 != 1) //10 numbers per line
				fout << " ";
			fout << i;
			if (last.size() == N)
				break;
			if (last.size() % 10 == 0)
				fout << endl;
		}
	}
	fout << '\n';

	return 0;
}