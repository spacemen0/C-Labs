#include <iostream>
#include <string>
#include<iomanip>
using namespace std;
int main() // hello
{
	cout << "input part" << endl;
	cout << setfill('=') << setw(10) << " " << endl;
	float firstprice, lastprice, stride, percentage;
	cout << "enter first price : ";
	cin >> firstprice;
	while (firstprice < 0)
	{
		cout << "error: first price must be at least 0 (zero)sek" << endl;
		cout << "enter first price : ";
		cin >> firstprice;
	}
	cout << "enter last price : ";
	cin >> lastprice;
	while (lastprice < firstprice)
	{
		cout << "error: last price must be at least equal to the first price" << endl;
		cout << "enter last price : ";
		cin >> lastprice;
	}
	cout << "enter stride : ";
	cin >> stride;
	while (stride < 0.01)
	{
		cout << "error: stride must be at least 0.01" << endl;
		cout << "enter stride : ";
		cin >> stride;
	}
	cout << "enter tax percent : ";
	cin >> percentage;
	while (percentage <= 0)
	{
		cout << "error: percentage must be above 0" << endl;
		cout << "enter tax percent : ";
		cin >> percentage;
	}
	cout << endl;
	//cout << firstprice <<" " <<lastprice << " " << stride << " " << percentage;

	cout << "tax table" << endl;
	cout << setfill('=') << setw(10) << " " << endl;
	cout << setfill(' ') << setw(20) << "price" << setw(20) << "tax" << setw(20) << "price with tax" << endl;
	cout << setfill('-') << setw(61) << " " << endl;
	int numiteration = (lastprice - firstprice)/stride ;
	//for (float i = firstprice; i <= lastprice; i = i + stride)
	for (int i = 0; i <= numiteration; ++i)
	{
		cout << setfill(' ') << setw(20) << fixed << setprecision(2) << firstprice+i*stride << setw(20) << 0.01f * (firstprice+i*stride) * percentage << setw(20) << (firstprice+stride*i) + 0.01f * (firstprice+stride*i)* percentage << endl;
	}
	//{
	//	cout << setfill(' ') << setw(20) << fixed << setprecision(2) << i << setw(20) << 0.01f *i * percentage<< setw(20) << i + 0.01f*i * percentage << endl;
	//}

}