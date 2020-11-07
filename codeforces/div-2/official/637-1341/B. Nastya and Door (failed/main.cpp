#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

pair<int, int> condensed(int length, vector<int> a) { //returns # of peaks and starting point
	int maxCounter = -1;
	int index;
	int buffer;

	//cout << "Size: " << a.size() << endl;
	if (a.size() != 1) {
		for (int j = 0; j < a.size()-1; j++) {
			int i = j;
			int counter = 0;
			int start = a[j], curr = a[j];
			//cout << "Length: " << start+length << endl;
			while (curr-start+1 < length && i < a.size()) {
				counter++;
				i++;
				curr = a[i];
				//cout << "Peak at: " << a[i] << endl;
			}
			i--;
			if (counter > maxCounter) {
				maxCounter = counter;
				buffer = start+length - a[i] - 2;
				index = max(0, start-buffer);
				//cout << "New buffer: " << buffer << endl;
				//cout << "New Index: " << index << endl;
				//cout << "New Max: " << maxCounter << endl;
			}
		}
	}
	else {
		return {1, (a[0]-(length-2))};
	}
	return {maxCounter, index};
}

int main(void) {
	int t;
	cin >> t;

	vector<vector<int>> mountains;
	vector<int> doorLengths;
	vector<vector<int>> peaks; //stores index of each peak

	for (int i = 0; i < t; i++) {
		int numMounts, tempLength;
		cin >> numMounts >> tempLength;
		vector<int> temp (numMounts);
		vector<int> tempPeak;

		for (int j = 0; j < numMounts; j++) {
			cin >> temp[j];
			if (j!=0 && j!= 1) {
				if (temp[j-1] > temp[j-2] && temp[j-1] > temp[j])
					tempPeak.push_back(j-1);
			}
		}
		mountains.push_back(temp);
		doorLengths.push_back(tempLength);
		peaks.push_back(tempPeak);
	}

	for (int i = 0; i < t; i++) {
		pair<int, int> ans =  condensed(doorLengths[i], peaks[i]);
		ans.first++;
		ans.second++;
		cout << ans.first << " " << ans.second << endl;


	}

	return 0;
}