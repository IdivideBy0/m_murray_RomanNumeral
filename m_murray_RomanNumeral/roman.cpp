#include <iostream>
#include <string>
#include "roman.h"


using namespace std;


RomanType::RomanType()
{

}

RomanType::RomanType(string)
{
	romanStr = "";
}
RomanType::RomanType(int)
{
	arabicInt = 0;
}

RomanType::~RomanType()
{

}


void RomanType::setRomanString(string instr)
{
	//romanStr = ""; //initialize string
	romanStr = instr;
}

void RomanType::setArabic(int userint)
{
	//arabicInt = 0; //initialize to zero
	arabicInt = userint;
}

string RomanType::getRomanString() const
{
	
	return romanStr; 
}

int RomanType::getArabic() const
{
	return arabicInt;
	
}

void RomanType::printRoman()
{

	cout << romanStr << endl;
}

void RomanType::printArabic()
{

	cout << arabicInt << endl;
}

void RomanType::convertRoman(string romStr)
{

	int strLen = romStr.length();
	int previous = 0;
	int sum = 0;
	int romIndex = 0;
	bool invalid = false;

	while((romIndex < strLen) && (invalid == false)) 
		{
			switch(romStr[romIndex])
			{
			case 'M':
				sum = sum + 1000;
				if(previous < 1000)
				{
					sum = sum - 2 * previous;
				}
				previous = 1000;
				break;
			case 'D':
				sum = sum + 500;
				if(previous < 500)
				{
					sum = sum - 2 * previous;
				}
				previous = 500;
				break;
			case 'C':
				sum = sum + 100;
				if(previous < 100)
				{
					sum = sum - 2 * previous;
				}
				previous = 100;
				break;
			case 'L':
				sum = sum + 50;
				if(previous < 50)
				{
					sum = sum - 2 * previous;
				}
				previous = 50;
				break;
			case 'X':
				sum = sum + 10;
				if(previous < 10)
				{
					sum = sum - 2 * previous;
				}
				previous = 10;
				break;
			case 'V':
				sum = sum + 5;
				if(previous < 5)
				{
					sum = sum - 2 * previous;
				}
				previous = 5;
				break;
			case 'I':
				sum = sum + 1;
				if(previous < 1)
				{
					sum = sum - 2 * previous;
				}
				previous = 1;
				break;
			default:
				cout << "Non Roman numeral detected -->" << romStr[romIndex] << endl;
				invalid = true;
				sum = 0;
			} 

			romIndex++;

		} 
		arabicInt = sum;
}

void RomanType::convertArabic(int myint)
{

	// create a paralled lookup array

	int values[] = { 1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1 };
	string numerals[] = { "M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I" };
	string temp = "";

	for(int i = 0; i < 13; i++) // loop through the values in our array
	{
		while(myint >= values[i])
		{
			myint = myint - values[i]; // subtract from the number it found
			temp = temp + numerals[i]; // concatenate and build Roman numeral
		}

	}

	romanStr = temp;

}

bool RomanType::isRoman(string mystr)
{
	
	// variables needed for our loop
	int strLen = mystr.length();
	bool isRoman = false;
	int temp = 0;

	// loop through each character and test for an Arabic character
	for(int i = 0; i < strLen; i++)
	{
		
		temp = static_cast<int>(mystr[i]);
		
		if (temp == static_cast<int>('0') || temp == static_cast<int>('1') || temp == static_cast<int>('2') || temp == static_cast<int>('3') 
			 || temp == static_cast<int>('4') || temp == static_cast<int>('5') || 
		    temp == static_cast<int>('6') || temp == static_cast<int>('7') || temp == static_cast<int>('8') || temp == static_cast<int>('9'))
		{
			isRoman = false;
		}
		else
		{
			isRoman = true;
			break;
		}
		
	}

	return isRoman;

}