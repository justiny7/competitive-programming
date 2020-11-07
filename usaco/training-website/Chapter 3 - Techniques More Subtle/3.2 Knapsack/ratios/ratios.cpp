/*
ID: justiny7
LANG: C++
TASK: ratios
*/

//Another easy task, just a lot of if statements and some logic
//Also took me two tries because I forgot about division by 0 cases xp, though I noticed a flaw that may have ended up in division by 0
//So I changed it but didn't resubmit

#include <bits/stdc++.h>
using namespace std;

ifstream fin("ratios.in");
ofstream fout("ratios.out");

int target[3];
int ratios[3][3];

int main(void) {
	fin >> target[0] >> target[1] >> target[2];
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
			fin >> ratios[i][j];

	int a, b, c;
	for (a = 0; a < 100; a++)
		for (b = 0; b < 100; b++)
			for (c = 0; c < 100; c++) {
				int one, two, three;
				one = a * ratios[0][0] + b * ratios[1][0] + c * ratios[2][0];
				two = a * ratios[0][1] + b * ratios[1][1] + c * ratios[2][1];
				three = a * ratios[0][2] + b * ratios[1][2] + c * ratios[2][2];
				//cout << one << " " << two << " " << three << endl;
				if ((one != 0 || two != 0 || three != 0)
					&& (target[0] != 0 && target[1] != 0 && target[2] != 0)
					&& (one % target[0] == 0 && two % target[1] == 0 && three % target[2] == 0)
					&& (one / target[0] == two / target[1] && two / target[1] == three / target[2])) {
					fout << a << " " << b << " " << c << " " << one / target[0] << endl;
					return 0;
				}
				//Division by 0 cases
				else if (target[0] == 0 || target[1] == 0 || target[2] == 0 && (one != 0 || two != 0 || three != 0)) {
					int good = 0;
					int div = -1;
					if (target[0] == 0 && one == 0)
						good++;
					else if (target[0] != 0 && one % target[0] == 0) {
						good++;
						div = one / target[0];
					}

					if (target[1] == 0 && two == 0)
						good++;
					else if (target[1] != 0 && two % target[1] == 0 && div == -1) {
						good++;
						div = two / target[1];
					}
					else if (target[1] != 0 && two % target[1] == 0 && div != -1 && two / target[1] == div)
						good++;

					if (target[2] == 0 && three == 0)
						good++;
					else if (target[2] != 0 && three % target[2] == 0 && div == -1) {
						good++;
						div = three / target[2];
					}
					else if (target[2] != 0 && three % target[2] == 0 && div != -1 && three / target[2] == div)
						good++;

					if (good == 3) {
						fout << a << " " << b << " " << c << " " << div << endl;
						return 0;
					}
				}
			}

	fout << "NONE\n";

	return 0;
}