/*
ID: justiny7
LANG: C++
TASK: agrinet
*/

#include <iostream>
#include <fstream>

using namespace std;

ifstream fin("agrinet.in");
ofstream fout("agrinet.out");

int connections[101][101];
int dist[101];
bool in[101];
int N, graphSize = 1, ans;

const int BIG = 1e9 + 5;

int main(void) {
	fin >> N;
	for (int i = 0; i < N; i++) {
		dist[i] = BIG;
		for (int j = 0; j < N; j++)
			fin >> connections[i][j];
	}

	in[0] = true;
	for (int i = 0; i < N; i++)
		if (i != 0)
			dist[i] = connections[0][i];

	while (graphSize < N) {
		int minDist = BIG, minNode = 0;
		for (int i = 0; i < N; i++)
			if (dist[i] < minDist && !in[i]) {
				minNode = i;
				minDist = dist[i];
			}

		graphSize++;
		ans += dist[minNode];
		in[minNode] = true;

		for (int i = 0; i < N; i++)
			if (i != minNode)
				if (dist[i] > connections[minNode][i])
					dist[i] = connections[minNode][i];
	}

	fout << ans << endl;

	return 0;
}