#include "stdafx.h"
#include "CppUnitTest.h"
#include "Header.h"                                                         //include the project header file on  which we have do unit testing
using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace std;
namespace UnitTest2
{		
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(testfileexistence)                              // this test case will  check existence of our file in given path
		{
		ReadCSV* csv=new ReadCSV();
		int x=csv->testfileexistence();
		Assert::AreEqual(x,1);                                   //Assert::AreEqual is member function in cppunittestframework which  check our expected and actual value are same or not( if same then testcase will successful)
		}
	};
	TEST_CLASS(UnitTest2)
	{
	public:

		TEST_METHOD(testfileemptiness)                              //this test case will check our file is empty our not
		{
		ReadCSV* csv=new ReadCSV();
		int x=csv->testfileemptiness();
		Assert::AreNotEqual(x,0);                                //Assert::AreEqual is member function in cppunittestframework which  check our expected and actual value are same or not ( if not same then testcase will successful)    
		}
	};
	TEST_CLASS(UnitTest3)
	{
	public:

		TEST_METHOD(testcheckfilesize)                               //this test case will check that our programme is reading our total number of line of .csv file or not 
		{
		ReadCSV* csv=new ReadCSV();
		int x=csv->testcheckfilesize();
		Assert::AreEqual(x,1);
		}
	};
   TEST_CLASS(UnitTest4)
	{
	public:

		TEST_METHOD(testcelldatamissing)                           //this test case will check that our .csv file has any cell is empty or not 
		{
		ReadCSV* csv=new ReadCSV();
		int x=csv->testcelldatamissing();
		Assert::AreEqual(x,1);
		}
	};
    TEST_CLASS(UnitTest5)
	{
	public:

		TEST_METHOD(testfileextension)                            // this test case will check our file is in.csv extension or not
		{
		ReadCSV* csv=new ReadCSV();
		int x=csv->testfileextension();
		Assert::AreEqual(x,1);
		}
	};
}