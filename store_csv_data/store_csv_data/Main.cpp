#include "Main.h"
#include "ReadCSV.h"
int main()
{
	ifstream  inFile;
	string  Row;
	//method to open file
	string file="C:\\Users\\akki9\\Desktop\\2.csv";
	inFile.open(file, ios::in);
	if (!inFile) 
	{
		cout << "Can't open input file " << endl;
		getchar();
		exit(1);
	}
	ReadCSV* rd=new ReadCSV();
	//this while loop terminate when there is no row to read further 
	while (getline(inFile,Row))
	{
		//here we calling  updateLine function of class ReadCSV by rd
		rd->Update_Line(Row);
		rd->Parse();
	}
	rd->Print_Csv_Files_Data();
	return 0;
}
