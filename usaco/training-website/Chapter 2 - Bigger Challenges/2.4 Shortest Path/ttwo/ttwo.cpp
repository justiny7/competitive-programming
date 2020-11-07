/*
ID: justiny7
LANG: C++
TASK: ttwo
*/

//Ay worked first try lmao
//The "probImpos" thing it prob wrong but it worked so it worked
//(basically if it repeats over 100000 times then it's probably never going to happen)

#include <iostream>
#include <fstream>

using namespace std;

ifstream fin("ttwo.in");
ofstream fout("ttwo.out");

char map[10][10];
int fDir = 0, cDir = 0;
int Fx, Fy, Cx, Cy;

int main(void) {
	for (int i = 0; i < 10; i++)
		for (int j = 0; j < 10; j++) {
			fin >> map[i][j];
			if (map[i][j] == 'F')
				Fx = j, Fy = i;
			else if (map[i][j] == 'C')
				Cx = j, Cy = i;
		}


	//cout << Cx << " " << Cy << endl;
	//cout << Fx << " " << Fy << endl;

	int i = 0;
	bool probImpos = false;
	while (!(Fx == Cx && Fy == Cy)) {
		//Moves farmer
		switch (fDir) {
		case 0:
			if (Fy != 0 && map[Fy - 1][Fx] == '.') {
				map[Fy][Fx] = '.';
				Fy--;
				map[Fy][Fx] = 'F';
			}
			else
				fDir++;
			break;
		case 1:
			if (Fx != 9 && map[Fy][Fx+1] == '.') {
				map[Fy][Fx] = '.';
				Fx++;
				map[Fy][Fx] = 'F';
			}
			else
				fDir++;
			break;
		case 2:
			if (Fy != 9 && map[Fy + 1][Fx] == '.') {
				map[Fy][Fx] = '.';
				Fy++;
				map[Fy][Fx] = 'F';
			}
			else
				fDir++;
			break;
		case 3:
			if (Fx != 0 && map[Fy][Fx-1] == '.') {
				map[Fy][Fx] = '.';
				Fx--;
				map[Fy][Fx] = 'F';
			}
			else
				fDir = 0;
			break;
		}
		//Moves cows
		switch (cDir) {
		case 0:
			if (Cy != 0 && map[Cy - 1][Cx] != '*') {
				map[Cy][Cx] = '.';
				Cy--;
				map[Cy][Cx] = 'C';
			}
			else
				cDir++;
			break;
		case 1:
			if (Cx != 9 && map[Cy][Cx + 1] != '*') {
				map[Cy][Cx] = '.';
				Cx++;
				map[Cy][Cx] = 'C';
			}
			else
				cDir++;
			break;
		case 2:
			if (Cy != 9 && map[Cy + 1][Cx] != '*') {
				map[Cy][Cx] = '.';
				Cy++;
				map[Cy][Cx] = 'C';
			}
			else
				cDir++;
			break;
		case 3:
			if (Cx != 0 && map[Cy][Cx - 1] != '*') {
				map[Cy][Cx] = '.';
				Cx--;
				map[Cy][Cx] = 'C';
			}
			else
				cDir = 0;
			break;
		}
		
		i++;
		if (i > 100000) {
			probImpos = true;
			break;
		}

	}
	/*
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++)
			cout << map[i][j];
		cout << endl;
	}*/
	if (!probImpos)
		fout << i << endl;
	else
		fout << "0\n";
	


	return 0;
}