#include <fstream>
#include <iostream>
#include <sstream>
#include <algorithm>
#include <vector>
#include <map>
#include <iterator>
#include <string>
using namespace std;

int main(int argc, const char *argv[])
{
	ifstream in_file("test.cpp");
	ofstream out_file("output_file.cpp");
	if (!in_file || !out_file) {
		cout << "cannot open file!" << endl;
		return -1;
	}
	istream_iterator<string> is(in_file);       /* first iterator */
	istream_iterator<string> eof;               /* end of file iterator */
	vector<string> text;

	// using back_inserter to call container's push_back to insert new elements
	copy(is, eof, back_inserter(text));
	sort(text.begin(), text.end());

	ostream_iterator<string> os(out_file);
	copy(text.begin(), text.end(), os);
	return 0;
}
