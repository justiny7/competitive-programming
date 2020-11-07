/*
ID: justiny7
LANG: C++
TASK: numtri
*/

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

ifstream fin("numtri.in");
ofstream fout("numtri.out");
vector<vector<int>> triangle;

int N;

//First two methods I tried - both timed out (used DFS - what did I expect)
/*
//Method 1 - a more inefficient way of writing Method 2
int layer = 0, index = 0;
int maxS = 0;
int counter = 0;
int largestSum(vector<vector<int>> a, int n, int start, int curSum) {
	//counter++;
	if (layer == n)
		return curSum;
	for (int i = 0; i < 2; i++) {
		curSum += a[layer][index];
		layer++;
		index += i;
		maxS = max(maxS, largestSum(a, n, index, curSum));
		layer--;
		index -= i;
		curSum -= a[layer][index];
	}
	return maxS;
}

//Method 2 - basically just a better way to write Method 1
int MaxSum = 0;
void SUM(vector<vector<int>> a, int row, int col, int curSum) {
	if (row == a.size()) {
		MaxSum = max(MaxSum, curSum);
		return;
	}
	curSum += a[row][col];
	SUM(a, row + 1, col, curSum);
	SUM(a, row + 1, col + 1, curSum);
}*/

int main(void) {
	fin >> N;
	for (int i = 0; i < N; i++) {
		vector<int> temp(i + 1);
		for (int j = 0; j < i + 1; j++)
			fin >> temp[j];
		triangle.push_back(temp);
	}

	//Method 3 - find largest sum at the node and replace triangle with that value
	for (int i = 1; i < N; i++) { //Start at row 2
		for (int j = 0; j < i + 1; j++) {
			if (j == 0)
				triangle[i][j] += triangle[i - 1][j];
			else if (j == i)
				triangle[i][j] += triangle[i - 1][j - 1];
			else
				triangle[i][j] += max(triangle[i - 1][j], triangle[i - 1][j - 1]);
		}
	}
	int Max = 0;
	for (int i = 0; i < N; i++) 
		Max = max(Max, triangle[N - 1][i]);

	fout << Max << '\n';

	return 0;
}