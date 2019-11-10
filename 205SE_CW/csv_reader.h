
#define csv_reader_hpp
#include <stdio.h>
#include <fstream>
#include <stdio.h>
#include <string>
#include <vector>
#include "csv_data.h"



using namespace std;

class csv_reader
{
private:
	string csvFileName;
	vector<csv_data>csvDataList;
	float high_HighValue;
	float low_LowValue;

	void readHeader(ifstream &ip);
	void readData(ifstream &ip);
	//void storeData(ifstream& ip);

	

public:
	//constructor
	csv_reader(string fileName);

	void readFile();
	void displayCsvData();
	void calculateHighAndLowValue();
	float getHighHighValue();
	float getLowLowValue();

	
};