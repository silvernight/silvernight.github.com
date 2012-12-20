#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void ReadDataFromFileWBW()
{
	ifstream fin("test.cpp");
	string s;
	while (fin >> s) {
		cout << "Read from file:" << s << endl;
	}
}

void ReadDataFromFileLBLIntoCharArray()
{
	ifstream fin("test.cpp");
	const int LINE_LENGTH = 100;
	char str[LINE_LENGTH];
	while (fin.getline(str, LINE_LENGTH)) {
		cout << "Read from file: " << str << endl;
	}
}

void ReadDataFromFileLBLIntoString()
{
	ifstream fin("test.cpp");
	string s;
	while (getline(fin, s)) {
		cout << "Read from file:" << s << endl;
	}
}

void ReadDataWithErrChecking()
{
	string filename = "test.cpp";
	ifstream fin(filename.c_str());
	if (!fin) {
		cout << "Error opening" << filename << "for input" << endl;
		exit(-1);
	}
}

int main(int argc, const char *argv[])
{
	ReadDataFromFileWBW();
	cout << endl;

	ReadDataFromFileLBLIntoCharArray();
	cout << endl;

	ReadDataFromFileLBLIntoString();
	cout << endl;

	ReadDataWithErrChecking();
	return 0;
}
