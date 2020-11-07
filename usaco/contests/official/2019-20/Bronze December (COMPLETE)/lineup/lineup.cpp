//USACO Bronze 2019 December Contest Problem 3

#include <bits/stdc++.h>
using namespace std;

ofstream fout("lineup.out");
ifstream fin("lineup.in");

string names[8] = {
	"Beatrice",
	"Belinda",
	"Bella",
	"Bessie",
	"Betsy",
	"Blue",
	"Buttercup",
	"Sue"
};

int n, order[8];
vector<pair<int, int>> conditions;

int getIndex(string a) {
	for (int i = 0; i < 8; i++)
		if (names[i] == a)
			return i;
	return -1;
}

bool works() {
	int c = 0;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < 7; j++)
			if ((conditions[i].first == order[j] && conditions[i].second == order[j+1])
			 || (conditions[i].second == order[j] && conditions[i].first == order[j+1])) {
				c++;
				break;
			}
	return (c == n);
}

int main() {
	fin >> n;
	for (int i = 0; i < n; i++) {
		string temp1, temp2;
		string trash;

		fin >> temp1 >> trash >> trash >> trash >> trash >> temp2;
		conditions.push_back({getIndex(temp1), getIndex(temp2)});
	}
	for (int i = 0; i < 8; i++)
		order[i] = i;

	while (!works()) {
		if (!next_permutation(order, order+8))
			break;
	}

	for (int i = 0; i < 8; i++)
		fout << names[order[i]] << '\n';
	
	return 0;
}