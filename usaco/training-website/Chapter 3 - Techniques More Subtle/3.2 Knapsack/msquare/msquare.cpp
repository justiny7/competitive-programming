/*
ID: justiny7
LANG: C++
TASK: msquare
*/

#include <bits/stdc++.h>

//#define N_HASH 96997 //still just trying to find a workable hashing prime...
//AND THEN I learned about unordered_set gahhh why didn't I look this up earlier

using namespace std;

ifstream fin("msquare.in");
ofstream fout("msquare.out");

string target = "--------";
string start = "12345678";
//bool visited[100000]; //wayy more than enough for the 8! permutations
unordered_set <string> visited; //NOTE: need to include <unordered_set> cuz VS Compiler is wack

//stole this hash table formula off of USACO Data Structures page
/*
int convert(string square) {
	unsigned int a = 0;
	for (int i = 0; i < 8; i++)
		a = (a << 3) + square[i]; //and tried changing the bit shifts as well..
	return a % N_HASH;
}*/

string A(string square) {
	int a = square[0], b = square[1], c = square[2], d = square[3];
	square[0] = square[7];
	square[1] = square[6];
	square[2] = square[5];
	square[3] = square[4];
	square[7] = a;
	square[6] = b;
	square[5] = c;
	square[4] = d;
	return square;
}

string B(string square) {
	int a = square[3], b = square[4];
	square[3] = square[2];
	square[2] = square[1];
	square[1] = square[0];
	square[0] = a;
	square[4] = square[5];
	square[5] = square[6];
	square[6] = square[7];
	square[7] = b;
	return square;
}

string C(string square) {
	int a = square[1];
	square[1] = square[6];
	square[6] = square[5];
	square[5] = square[2];
	square[2] = a;
	return square;
}

void print(string square) {
	for (int i = 0; i < 4; i++)
		cout << square[i] << " ";
	cout << endl;
	for (int i = 7; i > 3; i--)
		cout << square[i] << " ";
	cout << endl;
}

int main(void) {
	for (int i = 0; i < 8; i++)
		fin >> target[i];

	queue<pair<string, string>> q; //Perm, then path
	q.push(make_pair(start, ""));
	while (!q.empty()) {
		string perm = q.front().first;
		//cout << ind << '\t' << perm << '\t' << q.front().second;
		if (visited.find(perm) == visited.end()) {
			visited.insert(perm);

			string path = q.front().second;
			int len = path.length();

			if (perm == target) {
				fout << len << endl << path << endl;
				return 0;
			}

			if ((len >= 1 && path[len - 1] != 'A') || len < 1) {
				q.push(make_pair(A(perm), path + "A"));
				//cout << "\tA pushed";
			}
			if ((len >= 3 && !(path[len - 1] == 'B' && path[len - 2] == 'B' && path[len - 3] == 'B'))
				|| len < 3) {
				q.push(make_pair(B(perm), path + "B"));
				//cout << "\tB pushed";
			}
			if ((len >= 3 && !(path[len - 1] == 'C' && path[len - 2] == 'C' && path[len - 3] == 'C'))
				|| len < 3) {
				q.push(make_pair(C(perm), path + "C"));
				//cout << "\tC pushed";
			}
		}
		//cout << endl;
		q.pop();
	}

	return 0;
}
