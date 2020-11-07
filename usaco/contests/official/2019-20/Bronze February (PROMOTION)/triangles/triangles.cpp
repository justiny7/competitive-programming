//Problem 1

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cmath>

using namespace std;

vector <int> x;
vector <int> y;
int height = 0, base1 = 0, base2 = 0, area = 0;

int main() {
	ofstream fout("triangles.out");
	ifstream fin("triangles.in");

	int N;
	fin >> N;
	for (int i = 0; i < N; i++) {
		int a, b;
		fin >> a >> b;

		x.push_back(a);
		y.push_back(b);
		cout << x[i] << " " << y[i] << endl;
	}
	cout << endl;
	for (int i = 0; i < N-1; i++) {					//Cycles through each pair of points
		//cout << "\n\n";
		for (int j = i+1; j < N; j++) {
			if (x[j] == x[i]) {						//Checks for equal x-values (same vertical line)
				height = abs(y[j] - y[i]);				//Height = dist. btwn points
				//cout << '\n' << y[j] << " - " << y[i] << " = " << height << endl;
				for (int k = 0; k < N; k++) {		//Cycles through every point again to check for same y-vals
					if (y[j] == y[k] && (j != k)) {				//Checks with high point
						base1 = abs(x[k] - x[j]);
						//cout << base1 << endl;
						if ((base1 * height >= area)) area = base1 * height;
					}
					else if (y[i] == y[k] && (i != k)) {		//Checks with low point
						base2 = abs(x[k] - x[i]);
						//cout << base2 << endl;
						if ((base2 * height >= area)) area = base2 * height;
					}

					base1 = base2 = 0;
				}
			}
		}
	}
	cout << area;
	fout << area << '\n';
	return 0;
}