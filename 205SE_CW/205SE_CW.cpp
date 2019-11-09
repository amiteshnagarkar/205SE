// 205SE_CW.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include "csv_reader.h"
#include <cstdlib>
#include <string>

using namespace std;

void main()
{

	string fileName;
	cout << "Enter the file name : ";
	cin >> fileName;

	//outClientFile.open(fileName.c_str());

	csv_reader fileReader(fileName);

	fileReader.readFile();



}









/* 

int main(int argc, const char* argv[]) {
	// insert code here...

	//csv_reader fileReader;
	//**csv_reader fileReader1("/Users/amiteshnagarkar/University/205SE/testData/BTChist.csv");
	 //csv_reader fileReader1("/Users/amiteshnagarkar/University/205SE/testData/BTChist2.csv");
	 //csv_reader fileReader1("/Users/amiteshnagarkar/University/205SE/testData/BTChist3.csv");
	//csv_reader fileReader1("/Users/amiteshnagarkar/University/205SE/testData/BTChist4.csv");
	//csv_reader anotherfile("Amitesh");
	//csv_reader fileReader1;
	//*csv_reader fileReader1 ();



	//fileReader.readFile();
	fileReader1.readFile();
	//data = fileReader1.getData();
	//Plotter plot(bar);
	//plot.drawGraph(data);
	//anotherfile.readFile();


   // csv_reader.readFile(filename);

	//*if (!in)
	perror("Error opening requested file");
	else {
	string span;
	if (!(in >> span))
		cerr << "Invalid file format (expected floating point value)\n";
	else
		cout << "span = " << span << '\n';
		}


		return 0;
}

*/

