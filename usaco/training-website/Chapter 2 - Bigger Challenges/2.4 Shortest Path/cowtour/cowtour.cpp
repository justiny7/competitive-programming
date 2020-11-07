/*
ID: justiny7
LANG: C++
TASK: cowtour
*/

#include <iostream>
#include <iomanip>
#include <cmath>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

ifstream fin("cowtour.in");
ofstream fout("cowtour.out");

int n; //# of pastures
double adj[150][150]; // weighted adjacency list of distances
double longest[150]; //stores distance from pasture i to its farthest neighbor
double diameters[150]; //stores diameter of field i
int whichField[150]; //which field is pasture i in?
int numFields = 0; //# of each field (for fillFields)
vector<int> x, y; // x- and y-coords of pastures
vector<string> matr; //adjacency matrix from fin

void fillFields(int pasture, int fieldNum) { //DFS to fill fields
	if (whichField[pasture] > -1)
		return;

	whichField[pasture] = fieldNum;
	for (int i = 0; i < n; i++) //Go through neighbor pastures and fill whichField of those pastures with the same pasture number
		if (adj[pasture][i] < 1e9)
			fillFields(i, fieldNum);
}

int main(void) {
	//set fout decimal to 6
	fout << setprecision(6) << fixed;

	//input
	fin >> n;
	x.resize(n);
	y.resize(n);
	matr.resize(n);
	for (int i = 0; i < n; i++)
		fin >> x[i] >> y[i];
	for (int i = 0; i < n; i++)
		fin >> matr[i];
	
	//fill adj with distances
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++) {
			if (i == j)
				adj[i][j] = 0;
			else if (matr[i][j] == '1')
				adj[i][j] = sqrt(pow(x[i] - x[j], 2) + pow(y[i] - y[j], 2));
			else
				adj[i][j] = 1e9 + 5;
		}

	/*
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++)
			cout << adj[i][j] << " ";
		cout << endl;
	}*/


	//Floyd-Marshall for distances - fills adj with the shortest path to each other point
	for (int k = 0; k < n; k++)
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				adj[i][j] = min(adj[i][k] + adj[k][j], adj[i][j]);

	// Fills whichField and counts how many fields
	fill(whichField, whichField+n, -1);
	for (int i = 0; i < n; i++)
		if (whichField[i] == -1) {
			fillFields(i, numFields);
			numFields++;
		}

	//Fills in longest[] and diameters[]
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++) {
			if (adj[i][j] < 1e9)
				longest[i] = max(adj[i][j], longest[i]);
			diameters[whichField[i]] = max(longest[i], diameters[whichField[i]]);
		}

	//Looks for pairs
	double minDiam = 1e9 + 5, curDiam;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			if (whichField[i] != whichField[j]) {
				curDiam = longest[i] + longest[j] + sqrt(pow(x[i] - x[j], 2) + pow(y[i] - y[j], 2));
				curDiam = max(curDiam, max(diameters[whichField[i]], diameters[whichField[j]]));
				minDiam = min(curDiam, minDiam);
			}
	
	fout << minDiam << endl;

	return 0;
}



/* TOO SLOW (ofc, O(N^5) alg for 150 max test case -_- ... what did I expect) */


/* Old code for finding distances from each point to another within a field

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (matr[i][j] == '1') {
				for (int ind = 0; ind < n; ind++) {
					if (ind != i && matr[j][ind] == '1') {
						matr[i][ind] = '1';
						if (adj[i][ind] == 0) {
							adj[i][ind] = adj[i][j] + adj[j][ind];
							dist[i][ind] = adj[i][ind];
						}
					}
					if (ind != j && matr[i][ind] == '1') {
						matr[j][ind] = '1';
						if (adj[j][ind] == 0) {
							adj[j][ind] = adj[j][i] + adj[i][ind];
							dist[j][ind] = adj[j][ind];
						}
					}
				}
			}
		}
	}*/


	//iterate through each possible pairing of points and run Floyd-Warshall on each
	//find the max dist of each Floyd-Marshall, then find the min of all maxes
	/*
	for (int i = 0; i < n - 1; i++) {
		for (int j = i + 1; j < n; j++) {
			//updates new path if there is not a path already between them
			if (adj[i][j] != 0)
				continue;

			//cout << "\nNow " << i << " will be paired with " << j << endl;

			adj[i][j] = sqrt(pow(x[i] - x[j], 2) + pow(y[i] - y[j], 2));
			adj[j][i] = adj[i][j];
			dist[i][j] = adj[i][j];
			dist[j][i] = adj[j][i];

			//cout << dist[j][i] << endl;

			//Floyd-Marshall
			float curMax = dist[i][j];
			for (int k = 0; k < n; k++)
				for (int a = 0; a < n; a++)
					for (int b = 0; b < n; b++)
						if (dist[a][k] + dist[k][b] < dist[a][b] && a != b) {
							//cout << "Before, the distance between " << a << " and " << b << " was " << dist[a][b] << endl;
							dist[a][b] = dist[a][k] + dist[k][b];
							//cout << "Now the shortest distance between " << a << " and " << b << " is " << dist[a][b] << endl;
							curMax = max(curMax, dist[a][b]);
						}

			maxes.push_back(curMax);

			//Reset distances
			adj[i][j] = adj[j][i] = 0;
			reset();
		}
	}

	float Min = 1e9 + 5;
	for (int i = 0; i < maxes.size(); i++) {
		//cout << maxes[i] << endl;
		Min = min(Min, maxes[i]);
	}

	fout << Min << endl;
	*/