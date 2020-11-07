#include <iostream>
#include <fstream>

using namespace std;

ifstream fin("moobuzz.in");
ofstream fout("moobuzz.out");

int N;

int main(void) {
	fin >> N;
	
	int multiple = N/8; //floored
	int lowest8th = multiple*8;
	int curr = 15*multiple - 1;
	//cout << curr << endl;

	int mod = N%8;
	//cout << mod << endl;
	switch (mod) {
	case 1:
		curr += 2;
		break;
	case 2:
		curr += 3;
		break;
	case 3:
		curr += 5;
		break;
	case 4:
		curr += 8;
		break;
	case 5:
		curr += 9;
		break;
	case 6:
		curr += 12;
		break;
	case 7:
		curr += 14;
		break;
	}

	fout << curr << '\n';

	return 0;
}