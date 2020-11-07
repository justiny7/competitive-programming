/*
ID: justiny7
LANG: C++
TASK: butter
*/

//Oh my god this was a monster of a problem but in the end, after learning heap/priority queues I finally got it!
//Time to see what chapter 3.3 has in store...

#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> intPair;

ifstream fin("butter.in");
ofstream fout("butter.out");

const int BIG = 1e9; //Maximum length btwn paths is 225 - nevermind, this is also used for dist[]

int n, p, C, ans = 1e9, curSize;
vector<vector<intPair>> adjList;
int dist[801];
bool visited[801];
vector<int> cowAt;
priority_queue <intPair, vector<intPair>, greater<intPair>> pq;

void reset(int source) {
	for (int g = 1; g <= p; g++) {
		dist[g] = BIG;
		visited[g] = false;
	}
	curSize = 0;
	dist[source] = 0;
	pq.push({ 0, source });
}

int main(void) {
	fin >> n >> p >> C;
	adjList.resize(p+1);
	for (int i = 0; i < n; i++) {
		int a;
		fin >> a;
		cowAt.push_back(a);
	}
	for (int i = 0; i < C; i++) {
		int a, b, dst;
		fin >> a >> b >> dst;
		adjList[a].push_back({ b, dst });
		adjList[b].push_back({ a, dst });
	}

	/*
	for (int i = 1; i <= p; i++) {
		cout << "Neighbors of " << i << ":\n";
		for (int j = 0; j < adjList[i].size(); j++) {
			cout << adjList[i][j].first << ", with length " << adjList[i][j].second << endl;
		}
		cout << endl;
	}*/

	//Run Dijktra's from each point (might be too slow - we'll see)
	//Ok, V^2 Dijkstra's is too slow - try Floyd-Warshall? Shld be O(V^3) to find distances + O(VN) to check shortest path
	//Nope, still too slow - might have to learn heap Dijkstra's... -_-
	//Ok, did some research and learned basics of STL priority queues - heap Dijktra time
	for (int l = 1; l <= p; l++) {
		reset(l);
		
		while (!pq.empty()) {
			int index = pq.top().second;
			pq.pop();
			visited[index] = true;
			for (int i = 0; i < adjList[index].size(); i++) {
				if (!visited[adjList[index][i].first]) {
					int neighbor = adjList[index][i].first;
					int len = adjList[index][i].second;

					if (dist[index] + len < dist[neighbor]) {
						dist[neighbor] = dist[index] + len;
						pq.push({ dist[neighbor], neighbor });
					}
				}
			}
		}
		for (int k : cowAt)
			if (k != l)
				curSize += dist[k];
		
		ans = min(ans, curSize);
	}
	
	fout << ans << endl;

	return 0;
}

/* Floyd-Marshall - ALSO TOO SLOW
	for (int i = 1; i <= p; i++) {
		for (int j = 1; j <= p; j++) {
			if (dist[i][j] == 0)
				dist[i][j] = BIG;
			//cout << dist[i][j] << " ";
		}
		//cout << endl;
	}
	//cout << endl;


	for (int k = 1; k <= p; k++)
		for (int a = 1; a <= p; a++)
			for (int b = 1; b <= p; b++)
				if (dist[a][k] + dist[k][b] < dist[a][b])
					dist[a][b] = dist[a][k] + dist[k][b];


	for (int i = 1; i <= p; i++) {
		for (int w : cowAt) {
			if (w != i)
				curSize += dist[i][w];
		}
		ans = min(ans, curSize);
		//cout << curSize << endl;
		curSize = 0;
	}


*/

/* V^2 DIJKSTRA'S - TOO SLOW

void reset(int source) {
	for (int g = 1; g <= p; g++) {
		dist[g] = BIG;
		visited[g] = false;
	}
	nodesVis = 0;
	curSize = 0;
	dist[source] = 0;
}


	for (int i = 1; i <= p; i++) {
		reset(i);
		while (nodesVis < p) {
			int index = 0;
			int temp = BIG;
			for (int j = 1; j <= p; j++)
				if (!visited[j]) {
					if (dist[j] < temp) {
						temp = dist[j];
						index = j;
					}
				}

			//cout << "index: " << index << endl;
			visited[index] = true;
			nodesVis++;

			for (int j = 1; j <= p; j++) {
				//cout << adj[index][j] << " ";
				if (adj[index][j] > 0)
					if (dist[index] + adj[index][j] < dist[j])
						dist[j] = dist[index] + adj[index][j];
			}
			//cout << endl;
		}
		for (auto k : cowAt)
			curSize += dist[k];

		ans = min(ans, curSize);
		//cout << curSize << endl;
	}
*/