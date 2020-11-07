/*
ID: justiny7
LANG: C++
TASK: runround
*/

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

ifstream fin("runround.in");
ofstream fout("runround.out");

int M;

int genNextNum(int a) { //Returns first number strictly greater than a with unique digits
	a++; //because we're looking for the next one greater than a

	string A = to_string(a); //Converts to a string so we can split into digits

	vector<int> digits;
	vector<int> visited;

	for (int i = 0; i < A.length(); i++)
		digits.push_back(A[i] - 48); //48 = ascii 0

	int index = 0; //index of current digit we're checking (if it's repeated or not)
	bool repeat = false;
	while (digits.size() != visited.size()) { //until we've visited the right number of approved digits
		for (int i : visited) //Look through the list of visited - if it's already been visited or it's 0, mark as a repeat
			if (digits[index] == i || digits[index] == 0) {
				repeat = true;
				break;
			}

		if (!repeat) { //If no repeat, just add this so visited and move onto next digit
			visited.push_back(digits[index]);
			index++;
		}
		else { //Otherwise...
			if (digits[index] != 9) { //If it's not a 9, just add 1
				digits[index]++;
				repeat = false;
			}
			else { //If it is a 9...
				if (digits[index - 1] != 9) { // If the one before it isn't a nine, add one to that and set the current one to 1
					digits[index - 1]++;
					digits[index] = 1; //By setting it to 1, you're guranteed to get to the next lowest number if 1 is already taken
					repeat = false;
					index--; //Index-- checks if the previous digit (the one we added 1 to) is already taken
				}
				else { //If the one before it is a nine...
					a++; //Add 1 to a
					return genNextNum(a); //Recurse until the one before isn't a nine
				}
			}
		}
	}

	int ans = 0; //In the end, convert all the digits into a single integer and return
	for (int i = 0; i < digits.size(); i++)
		ans += digits[i] * pow(10, digits.size() - i - 1);

	return ans;
}

bool isRunaround(int a) { //Tests to see if it's a runaround number
	string test = to_string(a); //Again, convert to string to look at digits more easily
	vector<int> visited; //Visited array
	int cur = test[0] - 48; //cur (currend digit) initializes to first digit in number
	int init = cur; //init = first number in array, we refer back to this to check if we ran around to the first number again
	int curInd = 0; //curInd (current index) inits to 0
	int size = test.length(); //size = how many digits in a
	visited.push_back(cur); //Start by pushing back first digit into visited

	while (visited.size() <= size) { //While visited doesn't have all the sizes yet (though not rly necessary)
		//cout << cur << " " << curInd << endl;
		curInd = (curInd + cur) % size; //Move to next digit
		cur = test[curInd] - 48; //Revalue current digit
		for (int i : visited) { //See if it's been visited
			if (cur == init && visited.size() == size) //If it's the first digit and we've visited everything else already, return true
				return true;
			else if (cur == i) //Otherwise, if it's already been visited, return false
				return false;
		}
		visited.push_back(cur); //Add current number to visited since it hasn't been visited yet
	}
	return true; //Base case - return true (it will never get here though, so technically irrevelant)
}

int main(void) {
	fin >> M; //Get first number

	int A = genNextNum(M); //Generate next number > M with distinct digits
	while (!isRunaround(A)) //While it's not a runaround number
		A = genNextNum(A); //Generate next number > current number with distinct digits

	fout << A << endl; //fout answer

	return 0;
}