#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
#include <vector>
#include<regex>
using namespace std;

string file="C:\\Users\\akki9\\Desktop\\2.csv";     //globally declaration of file 

class ReadCSV
{
	private:
			 string somestring;
			 vector< vector<string> > attributetable;
	public :
             ReadCSV(){}                                       // constructor with no argument
             void updateLine(string somestring1)               // this function is use to store csv row data in somestring from main of source
			 {                     
               somestring=somestring1;
             }
			 void updateAttribute( vector<string> vectorofstrings)        //this function store the data in 2d vector (in attributable )
			 {
				 this->attributetable.push_back(vectorofstrings);
			 }
            void parse();
            void print();

	        /*********************************************************/
	         int testfileextension()                                       // this function is use to check our file is in.csv extension or not
			 {
			 if(file.substr((file.size()-4),(file.size()))==".csv")
				 return 1;
			 else 
				 return 0;
	         }
			/*********************************************************/


	        /*********************************************************/
	         int testfileexistence()                                     // this function is use to check existence of our file in given path
			 {
		      ifstream inFile;
		      inFile.open(file, ios::in);
		      if (!inFile)
			     return 0;
			  else
		        return 1;
	          }
	        /**********************************************************/


	        /**********************************************************/
	         int testfileemptiness()                                     //this function is use to check our file is empty our not
			 {
		       ifstream inFile;
		       string username;
		       int t=0;
		       inFile.open(file, ios::in);
	           while (getline(inFile,username))                        //this while loop terminate when there is no row to read further 
			   {
			    t=username.size()+t;                                   //storing size of file (string size)
		       }
		       if(t==0)
			     return 0;
		       else
			     return 1;
	           }
	         /**********************************************************/


	        /**********************************************************/
		     int testcheckfilesize()                                      //this function is use to check that our programme is reading our total number of line of .csv file or not 
			 {
		      ifstream inFile;
		     string username;
		     int t=0;
			 inFile.open(file, ios::in);
			 while (getline(inFile,username))                      //this while loop terminate when there is no row to read further 
			 { 
			 t++;
			}
			 if(t==986)                                              // here 986 is our expected no of row of .csv file
				return 1;
			else
			    return 0;
			}
            /**********************************************************/


	        /**********************************************************/
             int testcelldatamissing()                                    //this function check that our .csv file has any cell is empty or not 
			 {
					ifstream inFile;
					string username;
					int t=0;
					int b=1;
					inFile.open(file, ios::in);
					while (getline(inFile,username))                                               //this while loop terminate when there is no row to read further 
						{
						while (username.length() != 0 && username.find(',') != string::npos)         //here we are breaking the row of .csv file 
								{
									size_t pos;
									string singleattribute;
									pos = username.find_first_of(',');                                //pos store the position of first "," in line
									singleattribute = username.substr(0, pos);
									try                                                                //here we use  exception handling (if singleattribute size is 0 then exception is occur and b become 0 which is use fruther in if case
										{
										 if (singleattribute.size()==0)
											  {
												  throw 0;
											  }
										 }
								    catch (int x) 
										 {
											 b=0;
										  }
									 username.erase(0, pos+1);                      //erase the string from star position to first "'"
									}
								 }
						if(b==0)
							return 0;
						else
							 return 1;
			 }
	        /***********************************************************/

};
int row=1;                                             //globally declare the row 
