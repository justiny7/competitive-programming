//USACO Bronze 2019 December Contest Problem 1

#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

struct Cow {
	int name;
	int pos;
};

int K, N;

int main() {
	ofstream fout ("gymnastics.out");
	ifstream fin ("gymnastics.in");

	fin >> K >> N;
	vector <vector <Cow> > schedule;

	for (int i = 0; i < K; i++) {
		int a;
		vector <Cow> b (N);
		for (int j = 0; j < N; j++) {
			fin >> a;
			Cow temp;
			temp.name = a;
			temp.pos = j;
			b[a-1] = temp;
		}
		schedule.push_back(b);
	}
	for (int i = 0; i < K; i++) {
		for (int j = 0; j < N; j++) {
			cout << schedule[i][j].name << " " << schedule[i][j].pos << '\t';
		}
		cout << endl;
	}
	int test = 0;
	int consistentPair = 0;
	int round;
	
	cout << "\n\n\n\n";

	for (int i = 0; i < N - 1; i++) {
		for (int k = i + 1; k < N; k++) {
			for (round = 0; round < K; round++) {
				if (schedule[round][i].pos < schedule[round][k].pos) {
					test++;
				}
				else if (schedule[round][i].pos > schedule[round][k].pos) {
					test--;
				}
			}
			if (test == K || test == -K) {
				consistentPair++;
				cout << i+1 << " " << k+1 << "     " << test << endl;
			}
			test = 0;
			
		}
	}

	cout << endl << consistentPair;
	fout << consistentPair << '\n';
	return 0;
}