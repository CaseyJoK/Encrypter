#include <iostream>
#include <iomanip>
using namespace std;

int originalNumber, Digit1, Digit2, Digit3, key, EncryptedDigit1, EncryptedDigit2, EncryptedDigit3, EncryptedNumber;

int main() ///produceEncryptedNumber
{
	void isolateDigits();
	void encryptDigits();
	void swapDigit1WithDigit3();
	void recomposeNumber();

	cout << "Enter the original three-digit number: ";
	cin >> originalNumber;
	cout << "Enter the key: ";
	cin >> key;

	isolateDigits();
	encryptDigits();
	swapDigit1WithDigit3();
	recomposeNumber();

	//The below code sets the width of the number to always have 3 digits and to fill any empty space with a 0 so if there is a leading 0 it will show it
	cout << "The encrpyted version of " << originalNumber << " is " << setw(3) << setfill('0') << EncryptedNumber;

	cout << "\n\n"; 
	system("pause"); 
	return 0;
}

void isolateDigits()
{

	Digit1 = (originalNumber / 100);
	Digit2 = (originalNumber / 10) % 10;
	Digit3 = originalNumber % 10;
}

void encryptDigits()
{
	EncryptedDigit1 = (Digit1 + key) % 10;
	EncryptedDigit2 = (Digit2 + key) % 10;
	EncryptedDigit3 = (Digit3 + key) % 10;

}

void swapDigit1WithDigit3() //this sets the order of the digits, swapping digit 1 and 3 and keeping digit 2 the same
{
	Digit1 = EncryptedDigit3;
	Digit2 = EncryptedDigit2;
	Digit3 = EncryptedDigit1;

}

void recomposeNumber() //this adds the numbers back together by multiplying the first digit by 100 to get the hundreds and so on
{
	EncryptedNumber = (Digit1 * 100) + (Digit2 * 10) + (Digit3);

}
