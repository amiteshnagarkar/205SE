
#define csv_reader_hpp
#include <stdio.h>
#include <fstream>
#include <stdio.h>
#include <string>

using namespace std;

class csv_reader
{
private:
	string csvFileName;
	void readHeader(ifstream &ip);
	void readData(ifstream &ip);


public:
	//constructor
	csv_reader(string fileName);

	void readFile();

};