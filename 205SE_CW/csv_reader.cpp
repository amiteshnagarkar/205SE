

#include "csv_reader.h"
#include <fstream>
#include <iostream>
#include <cstdlib>
#include <string>

using namespace std;

//contructor
csv_reader::csv_reader(string fileName)
{
	
	cout << "inside csv reader contructor\n";
	cout << fileName;
	this->csvFileName = fileName;

}


void csv_reader::readHeader(ifstream &ip)
{
	string date;
	string open;
	string high;
	string low;
	string close;
	string volume;
	string marketCap;

	//read header only once
	getline(ip, date, ',');
	getline(ip, open, ',');
	getline(ip, high, ',');
	getline(ip, low, ',');
	getline(ip, close, ',');
	getline(ip, volume, ',');
	getline(ip, marketCap);
	cout << "Headers read successfully \n";
	cout << date << ", " << open << "," << high << "," << low << "," << close << "," << volume << "," << marketCap;

}




//sample data
//C:\Amitesh\205SE\testData\BTChist.csv
void csv_reader::readData(ifstream &ip) 
{
	//read data until end of file
	int counter = 0;

	//temp variables
	string date;
	string open;
	string high;
	string low;
	string close;
	string volume;
	string marketCap;

	while (ip.good())
	{
		//increment counter
		++counter;

		getline(ip, date, ',');
		getline(ip, open, ',');
		getline(ip, high, ',');
		getline(ip, low, ',');
		getline(ip, close, ',');
		getline(ip, volume, ',');
		getline(ip, marketCap);

		std::cout << "\n" << "Date: " << date << ", Open: " << open << ", high: " << high << ", low: " << low << ", close: " << close << ", volume: " << volume << ", marketCap: " << marketCap << "\n";
	}
}





void csv_reader::readFile()
{
	printf("csv_reader::readFile\n");
	cout << "inside read file\n";
	cout << csvFileName;
	cout << "\n";

	ifstream ip(csvFileName);

	if (!ip.is_open())
	{
		cout << "Error: File Open\n";
	}
	else
	{
		cout << "File opened successfully\n";

		this->readHeader(ip);
		this->readData(ip);
	}
}



/* 


void csv_reader::readFile()
{
	printf ("csv_reader::readFile\n");
	printf ("reading file: %s\n", csvFileName.c_str());

	ifstream ip(csvFileName.c_str());

	if (!ip.is_open()) std::cout << "Error: File Open" << '\n';

	string date;
	string open;
	string high;
	string low;
	string close;
	string volume;
	string marketCap;
	int counter = 0;

	// read header
	getline(ip, date,',');
	getline(ip, open,',');
	getline(ip, high,',');
	getline(ip, low,',');
	getline(ip, close,',');
	getline(ip, volume,',');
	getline(ip, marketCap);

	while(ip.good())
	{
		++counter;
		cout << "Count = " << counter;
		getline(ip, date,',');
		getline(ip, open,',');
		getline(ip, high,',');
		getline(ip, low,',');
		getline(ip, close,',');
		getline(ip, volume,',');
		getline(ip, marketCap);

		std::cout << date << ", " << open << ", " << high << ", " << low << ", " << close << ", " << volume << ", " << marketCap << "\n";
	}
}

*/

