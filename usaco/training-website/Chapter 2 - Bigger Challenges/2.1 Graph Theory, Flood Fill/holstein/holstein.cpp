/*
ID: justiny7
LANG: C++
TASK: holstein
*/

#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

ifstream fin("holstein.in");
ofstream fout("holstein.out");

bool isDone(vector<int> a) {
	int i, counter = 0;
	for (i = 0; i < a.size(); i++)
		if (a[i] <= 0) counter++;
	return (counter == i);
}

string Hex[] = { "0", "1", "2", "3", "4", "5", "6", "7", "8", "9", "A", "B", "C", "D", "E", "F" };
char hexC[] = { '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F' };

string to_hex(int a, string str) { //appends a (in hex) to a string, then returns the string
	str.append(Hex[a]);
	return str;
}

int to_int(char a) { //hex to int
	for (int i = 0; i < 16; i++)
		if (a == hexC[i])
			return i;
	return -1;
}

bool isIn(int a, string b) {
	for (int i = 0; i < b.length(); i++) {
		if (hexC[a] == b[i])
			return true;
	}
	return false;
}

vector<pair<int,pair<string, vector<int>>>> states; //pathlen, string path (in hex), vector feed left in each bucket
int counter;
void solve(vector<int> reqs, vector<vector<int>> feed, int pathLen, int v, int g) {
	vector<int> test;
	if (pathLen == 1) {
		test = reqs;
		for (int i = 0; i < g; i++) {
			for (int j = 0; j < v; j++)
				test[j] -= feed[i][j];

			states.push_back({ 1, { to_hex(i, ""), test } });
			//cout << states[i].second.first << endl;
			if (isDone(test)) {
				return;
			}
			test = reqs;
		}
		counter = 0;
	}
	else {
		int p = counter;
		for (; states[p].first == states[counter].first; p++) {
			for (int i = to_int(states[p].second.first[states[p].second.first.length()-1]); i < g; i++) {
				test = states[p].second.second;
				if (isIn(i, states[p].second.first))
					continue;
				for (int j = 0; j < v; j++)
					test[j] -= feed[i][j];

				states.push_back({ pathLen, { to_hex(i, states[p].second.first), test } });
				//cout << states[states.size()-1].second.first << endl;

				if (isDone(test)) {
					return;
				}
			}
		}
		counter = p;
	}
	solve(reqs, feed, pathLen + 1, v, g);
}

int main(void) {
	int V, G; //V = # of vitamins, G = # of feeds
	fin >> V;

	vector<int> req(V); //requirements for a cow
	for (int i = 0; i < V; i++)
		fin >> req[i];

	fin >> G;
	vector<vector<int>> feeds;
	
	for (int i = 0; i < G; i++) {
		vector<int> temp(V);
		for (int j = 0; j < V; j++)
			fin >> temp[j];
		feeds.push_back(temp);
	}

	solve(req, feeds, 1, V, G);
	/*	
	for (int i = 0; i < states.size(); i++) {
		cout << states[i].second.first << " ";
		for (int j = 0; j < states[i].second.second.size(); j++)
			cout << states[i].second.second[j] << " ";
		cout << endl;
	}
	cout << counter << "\n\n\n";
	*/
	int size = states.size() - 1;
	fout << states[size].first;
	for (int i = 0; i < states[size].second.first.length(); i++) {
		fout << " " << to_int(states[size].second.first[i]) + 1;
	}
	fout << '\n';
	
	return 0;
}