// Lab1 Basic input and output

#include <iostream>
#include <string>
#include <iomanip>
#include <limits>
using namespace std;

int main()
{
	int a;
	double b;
	char c;
	string d;
	cout << "Enter one integer: ";
	cin >> a;
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	cout << "You entered the number: " << a << endl
		 << endl;
	cout << "Enter four integers: ";
	cin >> a;
	cout << "You entered the numbers: " << a << " ";
	cin >> a;
	cout << a << " ";
	cin >> a;
	cout << a << " ";
	cin >> a;
	cout << a << endl
		 << endl;
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	cout << "Enter one integer and one real number: ";
	cin >> a >> b;
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	cout << "The real is: " << setprecision(3) << fixed << setw(11) << right << b << endl;
	cout << "The integer is: " << setw(8) << right << a << endl
		 << endl;
	cout << "Enter one real and one integer number: ";
	cin >> b >> a;
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	cout << "The real is: " << setfill('.') << setw(11) << right << fixed << b << endl;
	cout << "The integer is: " << setfill('.') << setw(8) << right << a << endl
		 << endl;
	cout << "Enter a character: ";
	cin >> c;
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	cout << "You entered: " << c << endl
		 << endl;
	cout << "Enter a word: ";
	cin >> d;
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	cout << "The word '" << d << "' has " << d.length() << " character(s)." << endl
		 << endl;
	cout << "Enter an integer and a word: ";
	cin >> a >> d;
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	cout << "You entered '" << a << "' and '" << d << "'." << endl
		 << endl;
	cout << "Enter a charater and a word: ";
	cin >> c >> d;
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	cout << "You entered the string \"" << d << "\" and the character '" << c << "'." << endl;
	cout << "Enter a word and real number: ";
	cin >> d >> b;
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	cout << "You entered \"" << d << "\" and \"" << fixed << b << "\"." << endl
		 << endl;
	cout << "Enter a text-line: ";
	getline(cin, d);
	cout << "You entered \"" << d << "\"" << endl
		 << endl;
	cout << "Enter a second line of text: ";
	getline(cin, d);
	cout << "You entered \"" << d << "\"" << endl
		 << endl;
	cout << "Enter three words:";
	cin >> d;
	cout << "You entered: " << d << " ";
	cin >> d;
	cout << d << " ";
	cin >> d;
	cout << d << endl
		 << endl;
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	return 0;
}