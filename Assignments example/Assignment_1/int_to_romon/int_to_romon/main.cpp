#include <iostream>
#include <string>
using namespace std;

int main()
{
	string ones[] = { "", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX" },
		   tens[] = { "", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC" },
		   hundreds[] = { "", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM" },
		   thousands[] = { "", "M", "MM", "MMM", };
	
	string result;
	int number;
	int index;
	cout << "Enter an integer between 1 and 3999: ";
	cin >> number;

	if (number < 1 || number > 3999)
	{
		cout << "Invalid input";
	}
	else
	{
		//get the thousands digit number and convert to roman number
		index = number / 1000;
		result += thousands[index];
		number %= 1000;

		//get the hundreds digit number and convert to roman number
		index = number / 100;
		result += hundreds[index];
		number %= 100;

		//get the tens digit number and convert to roman number
		index = number / 10;
		result += tens[index];
		number %= 10;
	
		//convert the ones digit number to roman number
		result += ones[number];
	}
	cout << "The roman number is: " << result << endl;
	system("pause");
	return 0;
}