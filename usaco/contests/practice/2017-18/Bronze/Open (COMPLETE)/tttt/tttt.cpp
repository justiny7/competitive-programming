#include <bits/stdc++.h>
using namespace std;

//This is such an ugh solution but if it works it works (key words: if it works)

ofstream fout("tttt.out");
ifstream fin("tttt.in");

char Board[3][3];
unordered_set<string> vis;
unordered_set<char> win;

int isOne(int Case) {
	switch (Case) {
	case 1:
		if (Board[0][0] == Board[0][1] && Board[0][1] == Board[0][2]) {
			win.insert(Board[0][0]);
			return 1;
		}
		break;
	case 2:
		if (Board[1][0] == Board[1][1] && Board[1][1] == Board[1][2]) {
			win.insert(Board[1][0]);
			return 1;
		}
		break;
	case 3:
		if (Board[2][0] == Board[2][1] && Board[2][1] == Board[2][2]) {
			win.insert(Board[2][0]);
			return 1;
		}
		break;
	case 4:
		if (Board[0][0] == Board[1][0] && Board[1][0] == Board[2][0]) {
			win.insert(Board[0][0]);
			return 1;
		}
		break;
	case 5:
		if (Board[0][1] == Board[1][1] && Board[1][1] == Board[2][1]) {
			win.insert(Board[0][1]);
			return 1;
		}
		break;
	case 6:
		if (Board[0][2] == Board[1][2] && Board[1][2] == Board[2][2]) {
			win.insert(Board[0][2]);
			return 1;
		}
		break;
	case 7:
		if (Board[0][0] == Board[1][1] && Board[1][1] == Board[2][2]) {
			win.insert(Board[0][0]);
			return 1;
		}
		break;
	case 8:
		if (Board[0][2] == Board[1][1] && Board[1][1] == Board[2][0]) {
			win.insert(Board[0][2]);
			return 1;
		}
	}
	return 0;
}

void isTwo(int Case) {
	if (isOne(Case))
		return;
	string s = "";
	switch (Case) {
	case 1:
		if (Board[0][0] == Board[0][1] || Board[0][1] == Board[0][2] || Board[0][0] == Board[0][2]) {
			if (Board[0][0] == Board[0][1]) {
				s += Board[0][0];
				s += Board[0][2];
				sort(s.begin(), s.end());
			}
			else {
				s += Board[0][0];
				s += Board[0][1];
				sort(s.begin(), s.end());
			}
			vis.insert(s);
		}
		break;
	case 2:
		if (Board[1][0] == Board[1][1] || Board[1][1] == Board[1][2] || Board[1][0] == Board[1][2]) {
			if (Board[1][0] == Board[1][1]) {
				s += Board[1][0];
				s += Board[1][2];
				sort(s.begin(), s.end());
			}
			else {
				s += Board[1][0];
				s += Board[1][1];
				sort(s.begin(), s.end());
			}
			vis.insert(s);
		}
		break;
	case 3:
		if (Board[2][0] == Board[2][1] || Board[2][1] == Board[2][2] || Board[2][0] == Board[2][2]) {
			if (Board[2][0] == Board[2][2]) {
				s += Board[2][1];
				s += Board[2][0];
				sort(s.begin(), s.end());
			}
			else {
				s += Board[2][2];
				s += Board[2][0];
				sort(s.begin(), s.end());
			}
			vis.insert(s);
		}
		break;
	case 4:
		if (Board[0][0] == Board[1][0] || Board[1][0] == Board[2][0] || Board[0][0] == Board[2][0]) {
			if (Board[0][0] == Board[1][0]) {
				s += Board[0][0];
				s += Board[2][0];
				sort(s.begin(), s.end());
			}
			else {
				s += Board[0][0];
				s += Board[1][0];
				sort(s.begin(), s.end());
			}
			vis.insert(s);
		}
		break;
	case 5:
		if (Board[0][1] == Board[1][1] || Board[1][1] == Board[2][1] || Board[0][1] == Board[2][1]) {
			if (Board[2][1] == Board[0][1]) {
				s += Board[2][1];
				s += Board[1][1];
				sort(s.begin(), s.end());
			}
			else {
				s += Board[2][1];
				s += Board[0][1];
				sort(s.begin(), s.end());
			}
			vis.insert(s);
		}
		break;
	case 6:
		if (Board[0][2] == Board[1][2] || Board[1][2] == Board[2][2] || Board[0][2] == Board[2][2]) {
			if (Board[0][2] == Board[1][2]) {
				s += Board[2][2];
				s += Board[0][2];
				sort(s.begin(), s.end());
			}
			else {
				s += Board[1][2];
				s += Board[0][2];
				sort(s.begin(), s.end());
			}
			vis.insert(s);
		}
		break;
	case 7:
		if (Board[0][0] == Board[1][1] || Board[1][1] == Board[2][2] || Board[0][0] == Board[2][2]) {
			if (Board[0][0] == Board[1][1]) {
				s += Board[0][0];
				s += Board[2][2];
				sort(s.begin(), s.end());
			}
			else {
				s += Board[0][0];
				s += Board[1][1];
				sort(s.begin(), s.end());
			}
			vis.insert(s);
		}
		break;
	case 8:
		if (Board[0][2] == Board[1][1] || Board[1][1] == Board[2][0] || Board[0][2] == Board[2][0]) {
			if (Board[0][2] == Board[2][0]) {
				s += Board[1][1];
				s += Board[0][2];
				sort(s.begin(), s.end());
			}
			else {
				s += Board[2][0];
				s += Board[0][2];
				sort(s.begin(), s.end());
			}
			vis.insert(s);
		}
	}
}


int main() {
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
			fin >> Board[i][j];

	for (int i = 1; i <= 8; i++) {
		isOne(i);
		isTwo(i);
	}
	fout << win.size() << '\n' << vis.size() << '\n';

	return 0;
}