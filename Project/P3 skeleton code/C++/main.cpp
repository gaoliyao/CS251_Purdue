#include <iostream>
#include<string>
#include<sstream>
#include<fstream>
#include<vector>
using namespace std;


void read_part_1()
{
	// TODO: Part1 : Create hash table
}

void read_part_2()
{
	//TODO: Part 2: compute number of collisions
}

void read_part_3()
{
	//TODO: Part 3: create heap
}


int main(int argc, char *argv[])
{
	// Read in the test case
	ifstream inputfile;
	ofstream outputfile;
	
	inputfile.open(argv[1]);
	outputfile.open(argv[2]);

	string str;
	
	getline(inputfile, str);
	int part;
	stringstream convert(str);
	convert >> part; 

	switch(part)
	{
		case 1:
			read_part_1();
			break;
		case 2:
			read_part_2();
			break;
		case 3:
			read_part_3();
			break;
	}
	
	return 0;
}

