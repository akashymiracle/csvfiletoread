#include "ReadCSV.h"
#include "Main.h"
int ReadCSV :: Test_Cell_Data_Missing()                       
{
	ifstream inFile;
	string Row;
	int t=0;
	int b=1;
	string file="C:\\Users\\akki9\\Desktop\\2.csv";
	inFile.open(file, ios::in);
	//this while loop terminate when there is no row to read further in csv file
	while (getline(inFile,Row))
	{
		//here we are breaking the row of .csv file 
		while (Row.length() != 0 && Row.find(',') != string::npos)
		{
			size_t pos;
			string singleattribute;
			//pos store the position of first "," in line
			pos = Row.find_first_of(',');
			//here we are storing first data in singleattribute of the Row
			singleattribute = Row.substr(0, pos);
			/*here we use  exception handling (if singleattribute 
			size is 0 then exception is occur
			and b become 0 which is use fruther in if case */
			try
			{
				if (singleattribute.size()==0)
				{
					throw 0;
				}
			}
			catch (exception e) 
			{
				b=0;
			}
			//erase the string from star position to first ","
			Row.erase(0, pos+1);
		}
	}
	if(b==0)
		return 0;
	else
		return 1;
}
int ReadCSV :: Test_Check_File_Size()
{
	ifstream inFile;
	string Row;
	int rowsize=0;
	string file="C:\\Users\\akki9\\Desktop\\2.csv";
	inFile.open(file, ios::in);
	//this while loop terminate when there is no row to read further of csv file
	while (getline(inFile,Row))
	{ 
		rowsize++;
	}
	// here 986 is our expected no of row of .csv file
	if(rowsize==986)
		return 1;
	else
		return 0;
}
int ReadCSV :: Test_File_Emptiness()
{
	ifstream inFile;
	string  Row;
	int filesize=0;
	string file="C:\\Users\\akki9\\Desktop\\2.csv";
	inFile.open(file, ios::in);
	//this while loop terminate when there is no row to read further 
	while (getline(inFile,Row))
	{
		//storing size of file (string size)
		filesize=Row.size()+filesize;
	}
	if(filesize==0)
		return 0;
	else
		return 1;
}
int ReadCSV :: Test_File_Existence()
{
	ifstream inFile;
	string file="C:\\Users\\akki9\\Desktop\\2.csv";
	inFile.open(file, ios::in);
	if (!inFile)
		return 0;
	else
		return 1;
}
int ReadCSV :: Test_File_Extension()
{
	string file="C:\\Users\\akki9\\Desktop\\2.csv";
	if(file.substr((file.size()-4),(file.size()))==".csv")
		return 1;
	else
		return 0;
}
void ReadCSV :: Print_Csv_Files_Data()
{
	size_t  inner;
	size_t outer;
	for (outer = 0; outer < attributetable.size(); outer++) 
	{
		for (inner = 0; inner < attributetable[outer].size(); inner++) 
		{
			//printing the data of .csv file which is store in 2d vector attribute table
			cout<<attributetable[outer][inner]<<"\n";
		}
		cout<<endl;
	}
	getchar();
}
void ReadCSV :: Parse()
{
	vector<string> vectorofstrings;
	//here we are breaking the row of .csv file 
	while (somestring.length() != 0 && somestring.find(',') != string::npos)
	{
		size_t pos;
		string singleattribute;
		//pos store the position of first "," in line
		pos = somestring.find_first_of(',');
		singleattribute = somestring.substr(0, pos);
		/*exception handling (any data is missing from csv 
		cell it will give us first missing data's position)*/
		try  
		{
			if (singleattribute.size()==0)
			{
				throw 0;
			}
		}
		catch (exception e) 
		{
			cout<<"Error:"<<endl;
			cout <<"some data is missing in csv file "<<endl;
			getchar();
			exit(1);
		}
		vectorofstrings.push_back(singleattribute);
		//erasing data of somestring to store next data of csv file
		somestring.erase(0, pos+1);
	}
	vectorofstrings.push_back(somestring);
	Update_Attribute(vectorofstrings);
	vectorofstrings.clear();
}
