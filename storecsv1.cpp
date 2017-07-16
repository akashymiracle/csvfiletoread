#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
#include <vector>
#include<regex>
using namespace std;
class ReadCSV
{
private:
        string somestring;
public:
    ReadCSV(){}
    ReadCSV(string somestring1){
    somestring=somestring1;

    }
    string getValue(){

        return somestring;
    }
    void parse(vector< vector<string> > &attributetable);
    void print(vector< vector<string> > &attributetable);
};
int row=1;
void ReadCSV ::parse(vector< vector<string> > &attributetable)
{
	vector<string> vectorofstrings;

	string somestring=getValue();
     int col=1;
	while (somestring.length() != 0 && somestring.find(',') != string::npos)
	{
		size_t pos;
		string singleattribute;
		pos = somestring.find_first_of(',');
		singleattribute = somestring.substr(0, pos);
		/**************************************************************************************/
		//exception handling (any data is missing from csv cell it will give us first missing data's position)
		try {
              if (singleattribute.size()==0)
                    {
                      throw 0;
                    }
   }
   catch (int x) {
      cout <<"some data is missing in csv file at coloumn number:"<<col<<"  and row number :"<<row<<endl;
      exit(1);
   }

        col++;

        /***************************************************************************/

		vectorofstrings.push_back(singleattribute);
		somestring.erase(0, pos+1);
	}
	vectorofstrings.push_back(somestring);
	attributetable.push_back(vectorofstrings);

	vectorofstrings.clear();

}
int main()
{
   char inputFilename[] = "C:\\Users\\miracle\\Desktop\\2.csv";
   ifstream inFile;
   string username;
   size_t i;
   ReadCSV rt1;
   inFile.open(inputFilename, ios::in);
   if (!inFile) {
     cerr << "Can't open input file " << inputFilename << endl;
     getchar();
     exit(1);
   }
vector< vector<string> > attributetable;
   while (getline(inFile,username)) {

    ReadCSV rt2(username);

    rt2.parse(attributetable);
    row++;

   }

   rt1.print(attributetable);
}

void ReadCSV:: print(vector< vector<string> > &attributetable1){
    size_t inner, outer;

	for (outer = 0; outer < attributetable1.size(); outer++) {
		for (inner = 0; inner < attributetable1[outer].size(); inner++) {

			cout<< attributetable1[outer][inner] << "\n";
		}
		cout<<endl;
	}
	getchar();
}

