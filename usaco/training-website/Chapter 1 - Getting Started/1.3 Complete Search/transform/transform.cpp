/*
ID: justiny7
LANG: C++
TASK: transform
*/

#include <iostream>
#include <fstream>
#include <vector>

using namespace std;
//VECTOR ROTATION
template<typename T>
void printArray(const vector<vector<T>>& vch) {
	for (int i = 0; i < vch.size(); ++i) {
		for (int j = 0; j < vch[0].size(); ++j) {
			cout << vch[i][j] << " ";
		}
		cout << endl;
	}
}

template<typename T>
void rotateArray(vector<vector<T>>& v)
{
	vector<vector<T>>rotated;
	for (size_t i = 0; i < v[0].size(); i++) {
		vector<T> newRow;
		for (int j = v.size() - 1; j >= 0; j--) {
			newRow.push_back(v[j][i]);
		}
		rotated.push_back(newRow);
	}
	v = rotated;
}

template<typename T>
void reflectArray(vector<vector<T>>& v)
{
	vector<vector<T>>reflected;
	for (size_t i = 0; i < v[0].size(); i++) {
		vector<T> newRow;
		for (int j = v.size() - 1; j >= 0; j--) {
			newRow.push_back(v[i][j]);
		}
		reflected.push_back(newRow);
	}
	v = reflected;
}
////////////////////////////////////////////////////

int main(void) {
	ifstream fin("transform.in");
	ofstream fout("transform.out");

	int N;
	fin >> N;

	vector <vector<char>> map;
	vector <vector<char>> finished;
	
	for (int j = 0; j < N; j++) {
		vector <char> test;
		for (int i = 0; i < N; i++) {
			
			char a;
			fin >> a;
			test.push_back(a);
		}
		map.push_back(test);
	}
	for (int j = 0; j < N; j++) {
		vector <char> test;
		for (int i = 0; i < N; i++) {

			char a;
			fin >> a;
			test.push_back(a);
		}
		finished.push_back(test);
	}
	
	int counter = 0;
	bool Done = false;
	bool isDone = false;

	if (map == finished)
		Done = true;

	while (counter < 6) {
		for (int i = 1; i <= 3; i++) {
			rotateArray<char>(map);
			if (map == finished) {
				counter = i;
				isDone = true;
				break;
			}
		}
		if (isDone)
			break;
		rotateArray<char>(map);
		//printArray<char>(map);
		reflectArray<char>(map);
		//printArray<char>(map);
		for (int i = 0; i < 4; i++) {
			if (i == 0 && map == finished) {
				counter = 4;
				isDone = true;
				break;
			}
			else if (i != 0) {
				rotateArray<char>(map);
				if (map == finished) {
					counter = 5;
					isDone = true;
					break;
				}
			}
		}
		if (isDone)
			break;
		else counter = 7;
	}
	if (counter == 7 && Done == true)
		counter = 6;
	cout << counter;
	fout << counter << '\n';
	return 0;
}