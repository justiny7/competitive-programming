/*
ID: justiny7
LANG: C++
TASK: castle
*/

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

ifstream fin("castle.in");
ofstream fout("castle.out");

int M, N;
int map[51][51]; //Map, to divide into components
int walls[51][51]; //A 2x2 array to store wall values

//Converts to binary (to be easier to see where there are walls)
vector<int> binary(int a) {
	vector<int> b(4);
	fill(b.begin(), b.end(), 0);
	for (int i = 0; a > 0; i++) {
		b[i] = a % 2;
		a /= 2;
	}
	reverse(b.begin(), b.end());
	return b;
}

//Recursively goes through the map, dividing into components
int counter = 0;
void recCheck(int compNum, int y, int x) {
	if (map[y][x] == -1) {
		counter++;
		map[y][x] = compNum;
		if (binary(walls[y][x])[0] == 0) {
			//Check bottom
			recCheck(compNum, y+1, x);
		}
		if (binary(walls[y][x])[1] == 0) {
			//check right
			recCheck(compNum, y, x+1);
		}
		if (binary(walls[y][x])[2] == 0) {
			//check top
			recCheck(compNum, y-1, x);
		}
		if (binary(walls[y][x])[3] == 0) {
			//check left
			recCheck(compNum, y, x-1);
		}
	}
}

int main(void) {
	fin >> M >> N;

	for (int i = 0; i < N; i++) //Get walls, initialize map to -1
		for (int j = 0; j < M; j++) {
			fin >> walls[i][j];
			map[i][j] = -1;
		}

	int componentNum = -1; //start at -1 (b/c indexing start at 0, with the componentNum++)
	int MAX = 0, secMAX = 0; //for caluculating the max possible sum of two rooms (not neccesarily consecutive) so we can break early
	vector<int> sizes; //A vector of the sizes of each room (indexed according to room name, and int from 0 - rooms-1
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (map[i][j] == -1) {
				componentNum++;
				sizes.push_back(counter);
				if (counter > MAX) {
					secMAX = MAX;
					MAX = counter;
				}
				else if (counter > secMAX) secMAX = counter;
				counter = 0;
			}
			recCheck(componentNum, i, j);
		}
	}
	sizes.push_back(counter); //The loop misses the last if statement, so we have to recall it here
	if (counter > MAX) {
		secMAX = MAX;
		MAX = counter;
	}
	else if (counter > secMAX) secMAX = counter;
	
	/*
	// PRINTS MAP
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cout << map[i][j] << " ";
		}
		cout << endl;
	}
	*/
	sizes.erase(sizes.begin());
	//cout << endl;
	//PRINTS ROOM SIZE
	//for (int i = 0; i < sizes.size(); i++) cout << sizes[i] << " ";
	

	//Now find max # in each component, find max sum, find where we need to break the wall
	int curSum = 0, maxSum = 0, MAXSUM = MAX + secMAX; //MAXSUM is the sum of the top 2 room sizes
	int ansX = 0, ansY = 0; //x- and y- coordinates of the answer wall to break
	char ansDir = ' '; //The direction of the wall (either 'N' or 'E')
	bool quickDone = false; //If curSum = MAXSUM (max possible sum), then we're automatically done
	for (int j = 0; j < M; j++) {
		for (int i = N; i >= 0; i--) { // Cycles through y-vals backward b/c we want the southmost answer
			if (binary(walls[i][j])[2] == 1 && (i != 0 && map[i][j] != map[i - 1][j])) { //If there is a wall to the north
				//cout << i << ", " << j << endl;										// and it's a different room...
				//cout << "TOP\n";
				curSum = sizes[map[i][j]] + sizes[map[i - 1][j]]; //Add the sizes of the two rooms...
				//cout << "CurSum: " << curSum << endl;
				if (curSum == MAXSUM) { //Check if MAXSUM...
					ansY = i + 1;
					ansX = j + 1;
					ansDir = 'N';
					maxSum = curSum;
					quickDone = true;
					//cout << "\nquickdone\n";
				}
				else if (curSum > maxSum) { //Or a max sum
					ansY = i + 1;
					ansX = j + 1;
					ansDir = 'N';
					maxSum = curSum;
				}
			}
			if (quickDone)
				break;
			if (binary(walls[i][j])[1] == 1 && (j != M-1 && map[i][j] != map[i][j+1])) { //Same thing here but for the east
				//cout << i << ", " << j << endl;
				//cout << "RIGHT\n";
				curSum = sizes[map[i][j]] + sizes[map[i][j+1]];
				//cout << "CurSum: " << curSum << endl;
				if (curSum == MAXSUM) {
					ansY = i + 1;
					ansX = j + 1;
					ansDir = 'E';
					maxSum = curSum;
					quickDone = true;
					//cout << "\nquickdone\n";
				}
				else if (curSum > maxSum) {
					ansY = i + 1;
					ansX = j + 1;
					ansDir = 'E';
					maxSum = curSum;
				}
			}
			if (quickDone)
				break;
		}
		if (quickDone)
			break;
	}

	//Write answer to out file
	fout << sizes.size() << endl;
	fout << MAX << endl;
	fout << maxSum << endl;
	fout << ansY << " " << ansX << " " << ansDir << endl;
	return 0;
}