#include "Main.h"
class ReadCSV
{
private:
	string somestring;
	//In this code we use attributetable(2d vector) to store data of .csv file 
	vector< vector<string> > attributetable;
public :
	// constructor with no argument
	ReadCSV(){}
	//deconstructor
	~ReadCSV(){}
	// this function is use to store csv row data in somestring from main() of source
	void Update_Line(string somestring1) 
	{
		somestring=somestring1;
	}
	//this function store the data in 2d vector (in attributable )
	void Update_Attribute( vector<string> vectorofstrings)
	{
		this->attributetable.push_back(vectorofstrings);
	}
	void Parse();
	void Print_Csv_Files_Data();
	// this function is use to check our file is in.csv extension or not
	int Test_File_Extension();
	// this function is use to check existence of our file in given path
	int Test_File_Existence();
	//this function is use to check our file is empty our not
	int Test_File_Emptiness();
	/*this function is use to check that our programme is reading 
	our total number of line of .csv file or not */
	int Test_Check_File_Size();
	//this function check that our .csv file has any cell is empty or not 
	int Test_Cell_Data_Missing();
};