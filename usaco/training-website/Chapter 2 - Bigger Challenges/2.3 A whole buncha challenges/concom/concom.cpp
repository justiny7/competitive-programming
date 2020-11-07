/*
ID: justiny7
LANG: C++
TASK: concom
*/

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

ifstream fin("concom.in");
ofstream fout("concom.out");

int n;
vector<pair<int, int>> answers; //comp a controls b
int ownings[101][101]; //how much companies 1 owns of company 2
bool checked[101][101]; //check whether we already exhausted this company of being checked

int main(void) {
	fin >> n;
	for (int i = 0; i < n; i++) {
		int a, b, c;
		fin >> a >> b >> c;
		ownings[a][b] = c;
	}
	//for (int i = 0; i < answers.size(); i++)
	//	cout << "Company " << answers[i].first << " controls company " << answers[i].second << endl;
	/*
	for (int i = 1; i <= 100; i++)
		for (int j = 1; j <= 100; j++)
			if (ownings[i][j] > 50)
				cout << "Company " << i << " owns " << ownings[i][j] << "% of company " << j << endl;

	cout << "\n\n\n";
	*/


	for (int i = 1; i <= 100; i++)
		for (int j = 1; j <= 100; j++)
			if (ownings[i][j] > 50 && !checked[i][j]) {
				checked[i][j] = true;
				for (int m = 1; m <= 100; m++) {
					ownings[i][m] += ownings[j][m];
					ownings[i][m] = min(100, ownings[i][m]);
					//cout << "Company " << i << " now owns " << ownings[i][m] << "% of company " << m << endl;
				}
				i = 1;
				j = 1;
			}


	//cout << "\n\n\n";

	for (int i = 1; i <= 100; i++)
		for (int j = 1; j <= 100; j++)
			if (ownings[i][j] > 50 && i != j) {
				//cout << "Company " << i << " owns " << ownings[i][j] << "% of company " << j << endl;
				answers.push_back({ i, j });
			}

	sort(answers.begin(), answers.end());
	for (int i = 0; i < answers.size(); i++)
		fout << answers[i].first << " " << answers[i].second << endl;


	return 0;
}