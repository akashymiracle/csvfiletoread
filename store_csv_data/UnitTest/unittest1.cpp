#include "stdafx.h"
#include "CppUnitTest.h"
//include the project header file on  which we have do unit testing
#include "ReadCSV.h"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace std;
namespace UnitTest2
{		
	TEST_CLASS(UnitTest1)
	{
	public:
		TEST_METHOD(TestFileExistence)
		{
			ReadCSV* csv=new ReadCSV();
			int x=csv->Test_File_Existence();
			/*Assert::AreEqual is member function in cppunittestframework 
			which  check our expected and actual value are same
			or not( if same then testcase will successful)*/
			Assert::AreEqual(x,1); 
		}
	};
	TEST_CLASS(UnitTest2)
	{
	public:
		//this test case will check our file is empty our not
		TEST_METHOD(TestFileEmptiness)
		{
			ReadCSV* csv=new ReadCSV();
			int x=csv->Test_File_Emptiness();
			/*Assert::AreEqual is member function in cppunittestframework
			which  check our expected and actual value are same
			or not ( if not same then testcase will successful)*/
			Assert::AreNotEqual(x,0); 
		}
	};
	TEST_CLASS(UnitTest3)
	{
	public:
		/*this test case will check that our programme is reading
		our total number of line of .csv file or not */
		TEST_METHOD(TestCheckFilesize)
		{
			ReadCSV* csv=new ReadCSV();
			int x=csv->Test_Check_File_Size();
			Assert::AreEqual(x,1);
		}
	};
	TEST_CLASS(UnitTest4)
	{
	public:
		//this test case will check that our .csv file has any cell is empty or not 
		TEST_METHOD(TestCellDatamissing)
		{
			ReadCSV* csv=new ReadCSV();
			int x=csv->Test_Cell_Data_Missing();
			Assert::AreEqual(x,1);
		}
	};
	TEST_CLASS(UnitTest5)
	{
	public:
		// this test case will check our file is in.csv extension or not
		TEST_METHOD(TestFileExtension)
		{
			ReadCSV* csv=new ReadCSV();
			int x=csv->Test_File_Extension();
			Assert::AreEqual(x,1);
		}
	};
}