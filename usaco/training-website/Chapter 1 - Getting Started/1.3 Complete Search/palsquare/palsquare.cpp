/*
ID: justiny7
LANG: C++
TASK: palsquare
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
	ofstream fout("palsquare.out");
	ifstream fin("palsquare.in");

	int B; //base
	int sq; //square

	fin >> B;
	
	for (int i = 1; i <= 300; i++) {
		sq = pow(i, 2);
		string temp;
		char temp2[20];
		char temp3[20];
		temp = convert(temp2, B, sq);
		if (isPal(temp))
			fout << convert(temp3, B, i) << " " << temp << '\n';
	}

	return 0;
}