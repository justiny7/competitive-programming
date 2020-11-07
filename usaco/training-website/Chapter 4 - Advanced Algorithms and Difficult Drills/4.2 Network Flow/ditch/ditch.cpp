/*
ID: justiny7
LANG: C++
TASK: ditch
*/

#include <bits/stdc++.h>
#define EVER ;;
using namespace std;

ifstream fin("ditch.in");
ofstream fout("ditch.out");

//vector<vector<int>> adjList; //Realized adjList was unnecessary
int n, m, totflow, maxflow, maxloc, flow[201], prevn[201], capacity[201][201];
bool visited[201];

//Non-greedy approach

int main(void) {
	fin >> n >> m;
	//adjList.resize(m+1);
	for (int i = 0; i < n; i++) {
		int a, b, c;
		fin >> a >> b >> c;
		//adjList[a].push_back(b);
		capacity[a][b] += c; //Damnit forgot about repeats in the input -_-
	}

	for (EVER) {
		for (int i = 1; i <= m; i++) {
			prevn[i] = -1;
			flow[i] = 0;
			visited[i] = false;
		}
		flow[1] = 2e9;

		for (EVER) {
			maxflow = 0;
			maxloc = -1;

			for (int i = 1; i <= m; i++)
				if (!visited[i] && flow[i] > maxflow) {
					maxflow = flow[i];
					maxloc = i;
				}

			if (maxloc == -1)
				break;

			//cout << "maxloc: " << maxloc << '\n';

			visited[maxloc] = true;
			for (int i = 1; i <= m; i++)
				if (!visited[i] && flow[i] < min(maxflow, capacity[maxloc][i])) {
					prevn[i] = maxloc;
					flow[i] = min(maxflow, capacity[maxloc][i]);
				}
		}

		if (flow[m] == 0)
			break;

		int pathcap = flow[m];
		totflow += pathcap;

		int cur = m, next;
		while (cur != 1) {
			next = prevn[cur];
			capacity[next][cur] -= pathcap;
			capacity[cur][next] += pathcap;

			//cout << "path from " << next << " to " << cur << ": " << capacity[next][cur] << '\n';

			cur = next;
		}
	}

	fout << totflow << '\n';

	return 0;
}


/* old stuff

bool isPath() {
	queue<int> q;
	visited[1] = true;
	prevn[1] = -1;
	q.push(1);
	pathflow = 2e9;

	while (!q.empty()) {
		int next = q.front();
		//cout << "cur: " << next << '\n';
		q.pop();

		for (int i : adjList[next])
			if (!visited[i] && capacity[next][i] > 0) {
				//cout << "cap: " << capacity[next][i] << '\n';
				q.push(i);
				prevn[i] = next;
				visited[i] = true;
				pathflow = min(pathflow, capacity[next][i]);
			}
	}

	return visited[m];
}



	for (int i = 1; i <= m; i++) {
		prevn[i] = -1;
		visited[i] = false;
	}

	while (isPath()) {
		for (int i = m; i != 1; i = prevn[i]) {
			int last = prevn[i];
			capacity[last][i] -= pathflow;
			capacity[i][last] += pathflow;
		}

		totflow += pathflow;
		
		fill(visited, visited+m+1, false);
	}

*/