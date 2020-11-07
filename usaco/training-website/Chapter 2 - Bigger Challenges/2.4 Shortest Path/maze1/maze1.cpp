/*
ID: justiny7
LANG: C++
TASK: maze1
*/

//This code is kinda ew but it got the job done - 236 lines of monstrosity xp
//Even though most of it is debugging code, the main BFS searches were still kinda ugly imo
//But anyways, it was a fun problem to do

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <queue>

using namespace std;

ifstream fin("maze1.in");
ofstream fout("maze1.out");

int w, h;
vector<string> map; //to store map from fin
string maze[101][40]; //in the form "xxxx", where x is 0/1; represents existence of N, E, S, W walls, respective
pair<int, int> exit1 = { -1, -1 }, exit2 = {-1, -1};
int l1[101][40]; //stores length from exit 1
int l2[101][40]; //stores length from exit 2
int nLeft[4000]; //neighbors left (defined globally to init to 0)


int main(void) {
	//initialize path lengths to -1
	for (int i = 0; i < 100; i++)
		for (int j = 0; j < 38; j++) {
			l1[i][j] = -1;
			l2[i][j] = -1;
		}

	//Read input (and practice stringstream!!)
	string line1;
	getline(fin, line1);
	stringstream ss(line1);

	ss >> w >> h;
	
	map.resize(2*h+1);
	for (int i = 0; i < 2 * h + 1; i++)
		getline(fin, map[i]);

	// creates wall strings (so we know where walls are in the maze) for each cell
	// also records where exits are
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			string walls = "";
			if (map[2 * i][2 * j + 1] == '-')
				walls.append("1");
			else
				walls.append("0");

			if (map[2 * i + 1][2 * j + 2] == '|')
				walls.append("1");
			else
				walls.append("0");

			if (map[2 * i + 2][2 * j + 1] == '-')
				walls.append("1");
			else
				walls.append("0");

			if (map[2 * i + 1][2 * j] == '|')
				walls.append("1");
			else
				walls.append("0");

			// maps exit squares
			if (i == 0 && walls[0] == '0') {
				if (exit1.first == -1)
					exit1 = { j, i };
				else
					exit2 = { j, i };
			}
			else if (j == 0 && walls[3] == '0') {
				if (exit1.first == -1)
					exit1 = { j, i };
				else
					exit2 = { j, i };
			}
			else if (i == h - 1 && walls[2] == '0') {
				if (exit1.first == -1)
					exit1 = { j, i };
				else
					exit2 = { j, i };
			}
			else if (j == w - 1 && walls[1] == '0') {
				if (exit1.first == -1)
					exit1 = { j, i };
				else
					exit2 = { j, i };
			}

			maze[i][j] = walls;
		}
	}

	//If there's only one exit square (corners)
	if (exit2.first == -1) {
		exit2.first = exit1.first;
		exit2.second = exit1.second;
	}
	//cout << exit1.first << " " << exit1.second << endl;
	//cout << exit2.first << " " << exit2.second << endl;
	
	/*
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++)
			cout << maze[i][j] << " ";
		cout << endl;
	}
	*/


	//do bfs from each exit, then find min of l1[y][x] and l2[y][x] for every point in the maze, then do the max of that
	queue<pair<int, int>> q;
	q.push({ exit1.second, exit1.first });
	int curlev = 1;
	nLeft[curlev] = 1; //neighbors left

	/*           NOTE: Sets pathlen of l1 (and l2) to -2 if it's been added to the queue            */
	/* This is for tracking how many neighbors are left to check before incrementing the path length*/

	while (!q.empty()) {
		int y = q.front().first, x = q.front().second;
		q.pop();
		nLeft[curlev]--;

		//cout << "left: " << nLeft[curlev] << endl;
		//cout << "curlev: " << curlev << endl;

		if (l1[y][x] < 0) {
			l1[y][x] = curlev;

			if (maze[y][x][0] == '0' && y != 0 && l1[y - 1][x] == -1) {
				q.push({ y - 1, x });
				l1[y - 1][x] = -2;
				nLeft[curlev + 1]++;
			}
			if (maze[y][x][1] == '0' && x != w - 1 && l1[y][x + 1] == -1) {
				q.push({ y, x + 1 });
				l1[y][x + 1] = -2;
				nLeft[curlev + 1]++;
			}
			if (maze[y][x][2] == '0' && y != h - 1 && l1[y + 1][x] == -1) {
				q.push({ y + 1, x });
				l1[y + 1][x] = -2;
				nLeft[curlev + 1]++;
			}
			if (maze[y][x][3] == '0' && x != 0 && l1[y][x - 1] == -1) {
				q.push({ y, x - 1 });
				l1[y][x - 1] = -2;
				nLeft[curlev + 1]++;
			}
			if (nLeft[curlev] == 0)
				curlev++;
		}
	}
	/*
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++)
			cout << l1[i][j] << "\t";
		cout << endl;
	}*/


	//BFS for exit 2
	for (int i = 0; i < 4000; i++) //reusing variables haha
		nLeft[i] = 0;

	queue<pair<int, int>> q2;
	q2.push({ exit2.second, exit2.first });
	curlev = 1;
	nLeft[curlev] = 1; //neighbors left
	while (!q2.empty()) {
		int y = q2.front().first, x = q2.front().second;
		q2.pop();
		nLeft[curlev]--;

		//cout << "left: " << nLeft[curlev] << endl;
		//cout << "curlev: " << curlev << endl;

		if (l2[y][x] < 0) {
			l2[y][x] = curlev;

			if (maze[y][x][0] == '0' && y != 0 && l2[y - 1][x] == -1) {
				q2.push({ y - 1, x });
				l2[y - 1][x] = -2;
				nLeft[curlev + 1]++;
			}
			if (maze[y][x][1] == '0' && x != w - 1 && l2[y][x + 1] == -1) {
				q2.push({ y, x + 1 });
				l2[y][x+1] = -2;
				nLeft[curlev + 1]++;
			}
			if (maze[y][x][2] == '0' && y != h - 1 && l2[y + 1][x] == -1) {
				q2.push({ y + 1, x });
				l2[y + 1][x] = -2;
				nLeft[curlev + 1]++;
			}
			if (maze[y][x][3] == '0' && x != 0 && l2[y][x - 1] == -1) {
				q2.push({ y, x - 1 });
				l2[y][x-1] = -2;
				nLeft[curlev + 1]++;
			}
			if (nLeft[curlev] == 0)
				curlev++;
		}
	}
	/*
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++)
			cout << l2[i][j] << "\t";
		cout << endl;
	}*/

	int MIN = -1;
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			int minOfpts = min(l1[i][j], l2[i][j]);
			MIN = max(minOfpts, MIN);
		}
	}

	fout << MIN << endl;

	return 0;
}
