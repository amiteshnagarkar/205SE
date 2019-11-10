

#include "csv_reader.h"
#include <fstream>
#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>


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
	cout << date << ", " << open << "," << high << "," << low << "," << close << "," << volume << "," << marketCap << "\n";

}




//sample data
//C:\Amitesh\205SE\testData\BTChist2.csv
void csv_reader::readData(ifstream &ip) 
{
	//read data until end of file
	int counter = 0;

	//temp variables
	string date;
	string monthday;
	string year;

	
	string open;
	string high;
	string low;
	string close;

	//string volume;
	//string marketCap;
	

	while (ip.good())
	{
		//increment counter
		++counter;

		//read monthday & year separately, & combine to date.
		getline(ip, monthday, ',');
		getline(ip, year, ',');

		csv_data rowData;

		//adds separate comma, as comma is used as a delimeter, but date contain comma too.
		rowData.date = monthday + "," + year;

		getline(ip,open, ',');
		rowData.open = std::stof(open);

		getline(ip, high, ',');
		rowData.high = std::stof(high);

		getline(ip, low, ',');
		rowData.low = std::stof(low);

		getline(ip, close, ',');
		rowData.close = std::stof(close);

		getline(ip, rowData.volume, ',');
		getline(ip, rowData.marketCap);

		this->csvDataList.push_back(rowData);

		//std::cout << "\n" << "Date: " << date << ", Open: " << open << ", high: " << high << ", low: " << low << ", close: " << close << ", volume: " << volume << ", marketCap: " << marketCap << "\n";
	}
}

void csv_reader::displayCsvData()
{
	cout << "Displaying data in csv data list \n ";
	for (unsigned int i = 0; i < csvDataList.size(); i++)
	{
		csv_data rowData = csvDataList[i];

		std::cout << "\n" << "Date: " << rowData.date << ", Open: " << rowData.open << ", high: " << rowData.high << ", low: " << rowData.low << ", close: " << rowData.close << ", volume: " << rowData.volume << ", marketCap: " << rowData.marketCap << "\n";
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











