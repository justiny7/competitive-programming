/*
ID: justiny7
LANG: C++
TASK: dualpal
*/

#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
#include <cstring>

using namespace std;

char reVal(int num)
{
	if (num >= 0 && num <= 9)
		return (char)(num + '0');
	else
		return (char)(num - 10 + 'A');
}

void strev(char* str)
{
	int len = strlen(str);
	int i;
	for (i = 0; i < len / 2; i++)
	{
		char temp = str[i];
		str[i] = str[len - i - 1];
		str[len - i - 1] = temp;
	}
}

char* convert(char res[], int base, int inputNum)
{
	int index = 0;  // Initialize index of result 

	// Convert input number is given base by repeatedly 
	// dividing it by base and taking remainder 
	while (inputNum > 0)
	{
		res[index++] = reVal(inputNum % base);
		inputNum /= base;
	}
	res[index] = '\0';

	// Reverse the result 
	strev(res);

	return res;
}

bool isPal(string a) {
	int length = a.length();
	bool flag = true;
	for (int i = 0; i < length; i++) {
		if (a[i] != a[length - i - 1]) {
			flag = false;
			break;
		}
	}
	return flag;
}

int main(void) {
	ofstream fout("dualpal.out");
	ifstream fin("dualpal.in");

	int counter = 0;
	int N, S;
	
	fin >> N >> S;

	for (int i = S + 1; counter < N; i++) {
		int count = 0;
		for (int B = 2; B <= 10; B++) {
			char temp2[20];
			string temp = convert(temp2, B, i);
			if (isPal(temp)) count++;
			if (count == 2) {
				fout << i << '\n';
				cout << i << '\n';
				counter++;
				break;
			}
		}
	}

	return 0;
}