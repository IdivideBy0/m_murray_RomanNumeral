#include <string>


using namespace std;

class RomanType
{
public:

	//Constructor

	RomanType();
	RomanType(string);
	RomanType(int);

	//Destructor

	~RomanType();

	
	//test input type
	bool isRoman(string);

	// set the user input
	void setRomanString(string); 
	void setArabic(int);

	// get the values stored in our class variables
	string getRomanString() const; 
	int getArabic() const;

	void convertArabic(int); //convert an Arabic to Roman
	void convertRoman(string); // convert a Roman numeral to Arabic

	// print values of romanStr and arabicStr
	void printRoman();
	void printArabic();

private:
	string romanStr;
	int arabicInt;

};