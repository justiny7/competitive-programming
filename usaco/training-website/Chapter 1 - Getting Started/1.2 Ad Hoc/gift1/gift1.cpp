/*
ID: justiny7
TASK: gift1
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

class Person {				//A class for each individual person
public:						//Contains money to split, number of ppl to split with,
	int money;				//A vector of strings of the names of ppl it split with,
	int ppl;				//And its name
	vector <string> giving;
	string Name;
	Person(int n, int m, string name, vector <string> names)
	{
		money = m;
		for (int i = 0; i < n; i++)
		{
			giving.push_back(names[i]);
		}
		Name = name;
		ppl = n;
	}
	~Person() { };
};

int main()
{
	ofstream fout("gift1.out");
	ifstream fin("gift1.in");

	int NOP; // number of people
	fin >> NOP;

	vector <string> Names; //Important for retaining the order when writing to OUT file
	for (int i = 0; i < NOP; i++)
	{
		string c;
		fin >> c;
		Names.push_back(c);
	}	

	vector <Person> People; //Vector of people
	vector <int> Money; //Vector of money that corresponds to the vector "People"

	for (int i = 0; i < NOP; i++)
	{
		int NumofNames;
		int moneyTemp;
		string NameTemp;
		vector <string> NameListTemp;

		fin >> NameTemp;
		fin >> moneyTemp;
		fin >> NumofNames; //Intaking all of the information

		for (int j = 0; j < NumofNames; j++)
		{
			string c;
			fin >> c;
			NameListTemp.push_back(c);
		}


		Person TempPerson(NumofNames, moneyTemp, NameTemp, NameListTemp); //Creating each Person and pushing it back into the vector
		People.push_back(TempPerson);
		
		Money.push_back(0);
	}

	for (int k = 0; k < NOP; k++)
	{
		Money[k] -= People[k].money; //Subtracts money given
		if (People[k].ppl > 0) Money[k] += ((People[k].money) % (People[k].ppl)); //Adds leftover
		
		for (int i = 0; i < NOP; i++)
		{
			for (int j = 0; j < People[k].ppl; j++)
			{
				if (People[i].Name == People[k].giving[j]) Money[i] += ((People[k].money) / (People[k].ppl)); //Distributes money
			}
			cout << People[i].Name << '\t' << Money[i] << endl;
		}
		cout << endl;
	}
	for (int i = 0; i < NOP; i++)
	{
		for (int j = 0; j < NOP; j++)
		{
			if (Names[i] == People[j].Name) fout << People[j].Name << " " << Money[j] << '\n'; //Reorders & writes everyone's names and money to OUT file
		}
	}

	return 0;
}