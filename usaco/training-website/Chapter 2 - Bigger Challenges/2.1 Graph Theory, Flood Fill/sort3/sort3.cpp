/*
ID: justiny7
LANG: C++
TASK: sort3
*/

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

ifstream fin("sort3.in");
ofstream fout("sort3.out");

void print(vector<int>a) {
	for (int i = 0; i < a.size(); i++)
		cout << a[i] << " ";
	cout << endl;
}

int main(void) {
	int N;
	fin >> N;
	vector<int> medals (N);
	vector<int> correct;

	for (int i = 0; i < N; i++)
		fin >> medals[i];

	correct = medals;
	sort(correct.begin(), correct.end());
	int startof2s = lower_bound(correct.begin(), correct.end(), 2) - correct.begin();
	int startof3s = lower_bound(correct.begin(), correct.end(), 3) - correct.begin();

	int counter = 0;
	for (int num = 1; num <= 2; num++) {
		for (int i = N - 1; i >= 0; i--) {
			if (medals[i] == num && medals[i] != correct[i]) {
				if (i >= startof2s && i < startof3s) {
					for (int j = 0; j < N; j++) {
						if (medals[j] != correct[j] && medals[j] == 2) {
							int temp = medals[j];
							medals[j] = medals[i];
							medals[i] = temp;
							counter++;
							//print(medals);
							break;
						}
					}
				}
				else if (i >= startof3s) {
					for (int j = 0; j < N; j++) {
						if (medals[j] != correct[j] && medals[j] == 3) {
							int temp = medals[j];
							medals[j] = medals[i];
							medals[i] = temp;
							counter++;
							//print(medals);
							break;
						}
					}
				}
				i = N - 1;
			}
		}
	}
	fout << counter << endl;

	return 0;
}