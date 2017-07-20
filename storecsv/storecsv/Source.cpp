#include "Header.h"


void ReadCSV ::parse()
{
	vector<string> vectorofstrings;
    int col=1;
	while (somestring.length() != 0 && somestring.find(',') != string::npos)               //here we are breaking the row of .csv file 
	{
		size_t pos;
		string singleattribute;
		pos = somestring.find_first_of(',');                                              //pos store the position of first "," in line
		singleattribute = somestring.substr(0, pos);

		/**************************************************************************************/
		//exception handling (any data is missing from csv cell it will give us first missing data's position)
		try  
		{
              if (singleattribute.size()==0)
                    {
                      throw 0;
                    }
         }
       catch (int x) 
	   {
           cout <<"some data is missing in csv file at coloumn number:"<<col<<"  and row number :"<<row<<endl;         //if any cell data is missing it will show it position
            getchar();
	        exit(1);
       }
        col++;
        /***************************************************************************/

		vectorofstrings.push_back(singleattribute);
		somestring.erase(0, pos+1);
	}
	vectorofstrings.push_back(somestring);                                                        
	
	updateAttribute(vectorofstrings);
	vectorofstrings.clear();

}
int main()
{
	ifstream inFile;
	string username;
	size_t i;
	ReadCSV rt1;
	inFile.open(file, ios::in);                                                            //method to open file
	if (!inFile) 
	{
     cerr << "Can't open input file " << file << endl;
     getchar();
     exit(1);
	}
	ReadCSV* rd=new ReadCSV();                                                             
	while (getline(inFile,username))                                                           //this while loop terminate when there is no row to read further 
	{
		rd->updateLine(username);                                                             //here we calling  updateLine function of class ReadCSV by rd
		rd->parse();
		row++;
    }
	rd->print();
	return 0;
}

void ReadCSV:: print()
{
    size_t inner, outer;
	for (outer = 0; outer < attributetable.size(); outer++) 
	{
		for (inner = 0; inner < attributetable[outer].size(); inner++) 
		{

			cout<<attributetable[outer][inner]<<"\n";                                             //printing the data of .csv file which is store in 2d vector attribute table
		}
		cout<<endl;
	}
	getchar();
}