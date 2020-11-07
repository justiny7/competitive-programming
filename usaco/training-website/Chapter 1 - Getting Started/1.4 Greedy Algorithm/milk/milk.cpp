/*
ID: justiny7
LANG: C++
TASK: milk
*/

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

struct Milk {
	int units;
	int prices;

	bool operator() (Milk i, Milk j) { return (i.prices < j.prices); }
} milk;


int main(void) {
	ofstream fout("milk.out");
	ifstream fin("milk.in");

	vector <Milk> MILK;
	int N, M;
	int total = 0;

	fin >> N >> M;
	int remaining = N;

	for (int i = 0; i < M; i++) {
		int a, b;
		fin >> a >> b;
		Milk temp;
		temp.prices = a;
		temp.units = b;
		MILK.push_back(temp);
	}

	sort(MILK.begin(), MILK.end(), milk);

	for (int i = 0; i < M; i++) {
		if (MILK[i].units <= remaining) {
			total += MILK[i].units * MILK[i].prices;
			remaining -= MILK[i].units;
		}
		else if (MILK[i].units > remaining || remaining == 0) {
			total += remaining * MILK[i].prices;
			break;
		}
	}
	cout << total;
	fout << total << endl;

	return 0;
}