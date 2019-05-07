/*****************************************************************************************************************************************************
*																																					 *
*																Roman Numeral Converter																 *
*															 Written by Michael J. Murray															 *
*																	   3/6/2013																	     *
*																																					 *
*****************************************************************************************************************************************************/

// This program can take input as either a decimal (Arabic) or Roman numeral and convert it to either Roman, or Arabic.

#include <iostream>
#include <string>
#include <sstream>
#include "roman.h"

using namespace std;

void menu()
{
	cout << "<<<<<<<<<<<<<<<<<<<	 Roman Numeral Converter	>>>>>>>>>>>>>>>>>>>>>>" << endl << endl << endl;
	cout << "Enter a Roman or positive Arabic number." << endl;
	cout << "Enter 'Q' to quit." << endl;
	cout << "Input >>";
}


int main()
{

	string romanIn; // Our input variable
	int arabicNum = 0; // Int variable to hold our string that gets converted using stringstream 

	do
	{

	menu();
	
	getline(cin, romanIn);

		if(romanIn == "Q")
	{
		break; // Why run the rest of the do loop?
	}
	
	RomanType myRoman; //Let's declare and use our class to get some work done.
	
	
	if(myRoman.isRoman(romanIn)) // convert to arabic number
	{
		myRoman.setRomanString(romanIn);
		myRoman.convertRoman(myRoman.getRomanString());
		cout << "You entered Roman numerals      :" << myRoman.getRomanString() << endl;
		cout << "The Roman numerals are equal to :";
		myRoman.printArabic();
		cout << endl << endl;
	}
	else   // convert to Roman numerals
	{
		stringstream instr(romanIn); //prepare the string for extraction into an int 
		instr >> arabicNum;
		myRoman.setArabic(arabicNum);
		myRoman.convertArabic(myRoman.getArabic());
		cout << "You entered Arabic numerals             :" << myRoman.getArabic() << endl;
		cout << "The Arabic number converted to Roman is :";
		myRoman.printRoman();
		cout << endl << endl;;
	}

	}
	while(romanIn != "Q");
	return 0;
	

}