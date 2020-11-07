/*
ID: justiny7
LANG: C++
TASK: ariprog
*/

#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <unordered_set>

using namespace std;

void remove(std::vector<int>& v)
{
	std::vector<int>::iterator itr = v.begin();
	std::unordered_set<int> s;

	for (auto curr = v.begin(); curr != v.end(); ++curr) {
		if (s.insert(*curr).second)
			* itr++ = *curr;
	}

	v.erase(itr, v.end());
}

int main(void) {
	ifstream fin("ariprog.in");
	ofstream fout("ariprog.out");

	int N, M;
	fin >> N >> M;

	bool numbers[300000] = { false };
	vector<int> bisquares;
	for (int i = 0; i <= M; i++) {
		for (int j = i; j <= M; j++) {
			bisquares.push_back((int)(pow(i, 2) + pow(j, 2)));
			numbers[i * i + j * j] = true;
		}
	}
	sort(bisquares.begin(), bisquares.end());
	remove(bisquares);

	//for (int i = 0; i < bisquares.size(); i++) cout << bisquares[i] << endl; //Print elements of bisquares


	int MAX_DIF = (2*M*M) / (N-1);

	bool NONE = true;
	

	for (int i = 1; i <= MAX_DIF; i++) {
		for (int p = 0; p < bisquares.size(); p++) {
			int a = bisquares[p];
			for (int j = 0; j < N; j++) {
				if (!numbers[a])
					break;
				else if (j == N - 1) {
					fout << bisquares[p] << " " << i << '\n';
					cout << bisquares[p] << " " << i << '\n';
					NONE = false;
				}
				a += i;
			}
		}
	}

	if (NONE) fout << "NONE\n";
	
	return 0;
}