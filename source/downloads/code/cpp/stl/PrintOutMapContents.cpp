#include <fstream>
#include <iostream>
#include <sstream>
#include <algorithm>
#include <vector>
#include <map>
#include <iterator>
using namespace std;

ostream& operator <<(ostream& out, const string& str)
{
	return out << str;
}

string toString(const pair<const int, int>& value)
{
	ostringstream ost;
	ost << "(" << value.first << "," << value.second << ")";
	return ost.str();
}

int main(int argc, const char *argv[])
{
	map<int, int> imap;
	for (int i = 0; i < 10; ++i) 
		//imap.insert( map<int, int>::value_type(i, i*10) );
		imap[i] = i*10;
	
	transform(imap.begin(), imap.end(), ostream_iterator<string>(cout, " "), toString);
	cout << endl;
}
