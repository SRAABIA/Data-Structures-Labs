#include <iostream>
#include <fstream>
using namespace std;
int main()
{
	ifstream fr;
	ofstream fo;

	fr.open("input_file.txt");
	fo.open("output_file.txt");
	string var;
	while (!fr.eof())
	{
		getline(fr, var);
		fo << var;
	}
	fr.close();
	fo.close();

	ifstream frr;
	frr.open("output_file.txt");
	while (!frr.eof())
	{
		getline(frr, var);
		cout << var;
	}
	frr.close();
}