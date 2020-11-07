/*
ID: justiny7
LANG: C++
TASK: comehome
*/

/*
A fun problem overall, and my first time using Dijktra's c:
In retrospect, the parent part of Dijkstra's isn't needed, but it works anyway (way in time as well - all 0.004s except 1 0.007)
Probably one of my favorite problems thus far, despite the ugly code
*/

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

const int MAX_PASTURES = 52;
const int BIG = 1e9 + 5;

string alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz"; //The lowercase letters aren't necessary for the problem, but they're
																		  //useful for the Dijktra's table (see below)
ifstream fin("comehome.in");
ofstream fout("comehome.out");


int p; //# of paths
int paths[MAX_PASTURES][MAX_PASTURES]; //weighted adj matrix for length btwn barn i and j, with i and j representing char of barn
int dist[MAX_PASTURES];
int parent[MAX_PASTURES]; //not needed in retrospect
bool visited[MAX_PASTURES];
int cowAt[MAX_PASTURES]; // 0 = not in graph, 1 = no cow, 2 = cow
vector<int> pastures; // # of each pasture
int numPasts;
int pastsVisited;

int main(void) {
	fin >> p;
	for (int i = 0; i < MAX_PASTURES; i++)
		for (int j = 0; j < MAX_PASTURES; j++)
			paths[i][j] = BIG;

	//Input stuff
	for (int i = 0; i < p; i++) {
		char a, b;
		int c;
		fin >> a >> b >> c;

		//Input stuff into paths (adj matrix) and cowAt (is there a cow at pasture i with 0 <= i <= 52, for pastures a-z and A-Z
		if (a <= 89 && b <= 89 && a != b) {
			//cout << "both\n";
			cowAt[a - 'A'] = 2;
			cowAt[b - 'A'] = 2;
			paths[a - 'A'][b - 'A'] = min(c, paths[a-'A'][b-'A']);
			paths[b - 'A'][a - 'A'] = paths[a - 'A'][b - 'A'];
		}
		else if (a <= 89 && b > 90 && a != b) {
			//cout << "first\n";
			cowAt[a - 'A'] = 2;
			cowAt[b - 'a' + 26] = 1;
			paths[a - 'A'][b - 'a' + 26] = min(c, paths[a - 'A'][b - 'a' + 26]);
			paths[b - 'a' + 26][a - 'A'] = paths[a - 'A'][b - 'a'+26];
		}
		else if (a > 90 && b <= 89 && a != b) {
			//cout << "second\n";
			cowAt[b - 'A'] = 2;
			cowAt[a - 'a' + 26] = 1;
			paths[a - 'a' + 26][b - 'A'] = min(c, paths[a - 'a' + 26][b - 'B']);
			paths[b - 'A'][a - 'a' + 26] = paths[a - 'a' + 26][b - 'A'];
		}
		else if (a > 90 && b > 90 && a != b) {
			//cout << "none\n";
			cowAt[a - 'a' + 26] = 1;
			cowAt[b - 'a' + 26] = 1;
			paths[a - 'a' + 26][b - 'a' + 26] = min(c, paths[a - 'a' + 26][b - 'a' + 26]);
			paths[b - 'a' + 26][a - 'a' + 26] = paths[a - 'a' + 26][b - 'a' + 26];
		}
		else if (a != 90 && b == 90 && a != b) {
			//cout << "2 is barn\n";
			if (a > 89) {
				cowAt[a - 'a' + 26] = 1;
				paths[25][a - 'a' + 26] = min(c, paths[25][a - 'a' + 26]);
				paths[a - 'a' + 26][25] = paths[25][a - 'a' + 26];
			}
			else {
				cowAt[a - 'A'] = 2;
				paths[25][a - 'A'] = min(c, paths[25][a - 'A']);
				paths[a - 'A'][25] = paths[25][a - 'A'];
			}
		}
		else if (a == 90 && b != 90 && a != b) {
			if (b > 89) {
				cowAt[b - 'a' + 26] = 1;
				paths[25][b - 'a' + 26] = min(c, paths[25][b - 'a' + 26]);
				paths[b - 'a' + 26][25] = paths[25][b - 'a' + 26];
			}
			else {
				cowAt[b - 'A'] = 2;
				paths[25][b - 'A'] = min(c, paths[25][b - 'A']);
				paths[b - 'A'][25] = paths[25][b - 'A'];
			}
		}
	}

	//Input debug stuff
	/*
	for (int i = 0; i < 52; i++) {
		for (int j = 0; j < 52; j++)
			cout << paths[i][j] << " ";
		cout << endl;
	}
	
	for (int i = 0; i < 52; i++)
		cout << i << ": " << cowAt[i] << endl;
	*/
	

	//Initializes numPast, dist and parent (visited is already init to false)
	for (int i = 0; i < MAX_PASTURES; i++) {
		dist[i] = BIG;
		parent[i] = -1;
		if (cowAt[i] > 0)
			pastures.push_back(i);
	}
	pastures.push_back(25);
	//for (int i : pastures)
	//	cout << i << endl;
	//cout << "# of pastures:" << pastures.size() << endl;

	numPasts = pastures.size();
	dist[25] = 0;

	// Dijkstra's from barn
	while (pastsVisited < numPasts) {
		int minDist = 0; // unvisited pasture w/ min dist
		int temp = BIG;
		for (int i : pastures)
			if (!visited[i]) {
				if (dist[i] < temp) {
					temp = dist[i];
					minDist = i;
				}
				//cout << i << endl;
			}

		//cout << minDist << endl;
		visited[minDist] = true;
		pastsVisited++;

		for (int j : pastures)
			if (paths[minDist][j] < BIG) {
				if (dist[minDist] + paths[minDist][j] < dist[j]) {
					dist[j] = dist[minDist] + paths[minDist][j];
					parent[j] = minDist;
				}
			}
	}
	//cout << "Node\tVisited\tDist\tParent\n"; //uncomment this (and comment below) for table

	int ans = BIG, ansCharAt = 0;
	for (int i : pastures) {
		//cout << alphabet[i] << '\t' << visited[i] << '\t' << dist[i] << '\t' << parent[i] << endl; //uncomment this (and comment above) for table
		if (cowAt[i] == 2) {
			if (dist[i] < ans) {
				ans = dist[i];
				ansCharAt = i;
			}
		}
	}

	fout << alphabet[ansCharAt] << " " << ans << endl;

	return 0;
}