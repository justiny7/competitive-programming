#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ifstream fin("test.in");

int vis[1000][1000];
int n, m, cnt = 0;

void print() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++)
			cout << vis[i][j] << '\t';
		cout << endl;
	}
}

void recCheck(int compNum, int y, int x) {
	if (vis[y][x] == 0) {
		vis[y][x] = compNum;
		//print();
		if (y < n-1) {
			//Check bottom
			recCheck(compNum, y + 1, x);
		}
		if (x < m-1) {
			//check right
			recCheck(compNum, y, x + 1);
		}
		if (y > 0) {
			//check top
			recCheck(compNum, y - 1, x);
		}
		if (x > 0) {
			//check left
			recCheck(compNum, y, x - 1);
		}
	}
}



int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	
	bool doesWork = true;
	/*fin >> n >> m;*/cin >> n >> m;
	string map[1000];
	for (int j = 0; j < n; j++)
		/*fin >> map[j];*/cin >> map[j];

	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			if (map[i][j] == '.')
				vis[i][j] = -1;
		
	bool alreadyB = false, alreadyW = false;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (map[i][j] == '#' && !alreadyB)
				alreadyB = true;
			else if (map[i][j] == '.' && !alreadyW && alreadyB)
				alreadyW = true;
			else if (map[i][j] == '#' && alreadyB && alreadyW) {
				doesWork = false;
				break;
			}

		}
		alreadyB = false, alreadyW = false;
		if (!doesWork)
			break;
	}

	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (map[j][i] == '#' && !alreadyB)
				alreadyB = true;
			else if (map[j][i] == '.' && !alreadyW && alreadyB)
				alreadyW = true;
			else if (map[j][i] == '#' && alreadyB && alreadyW) {
				//cout << j << ", " << i << endl;
				doesWork = false;
				break;
			}

		}
		alreadyB = false, alreadyW = false;
		if (!doesWork)
			break;
	}
	int temp = 0;
	if (m == 1 || n == 1) {
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
				if (map[i][j] == '.')
					temp++;
		if (temp != n * m)
			doesWork = false;
	}
	
	if (doesWork) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (vis[i][j] == 0) {
					cnt++;
					//cout << i << ", " << j << endl;
					recCheck(cnt, i, j);
				}
				//print();
			}
		}
	}
	//print();

	if (!doesWork)
		cout << "-1\n";
	else
		cout << cnt << endl;
		

	return 0;
}