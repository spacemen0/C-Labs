#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
using namespace std;
int main() // hello
{
	ifstream ifs{"random.txt"};
	string word{};
	size_t shortest = 100, longest = 0;
	string shortestword, longestword;
	size_t totallength = 0, totalword = 0;
	float averagelength = 0.0;
	while (ifs >> word)
	{
		++totalword;
		totallength = totallength + word.size();
		if (word.size() < shortest)
		{
			shortest = word.size();
			shortestword = word;
		}
		if (word.size() > longest)
		{
			longest = word.size();
			longestword = word;
		}
	}
	ifs.close();

	cout << "there are " << totalword << " words in the file." << endl;
	cout << "the shortest word was " << shortestword << " with " << shortest << " character(s)." << endl;
	cout << "the longest word was " << longestword << " with " << longest << " character(s)." << endl;
	cout << "the average length was " << fixed << setprecision(2) << totallength / totalword << " character(s)." << endl;
}