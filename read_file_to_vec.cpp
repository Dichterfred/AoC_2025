#include <fstream>
#include <string>
#include <vector>
#include <iostream>

using namespace std;


vector<std::string> readLineByLine( const string& path) {
    vector<string> input;
    string line;
    ifstream inputfile (path);
    if (inputfile.is_open()) {
        while( getline( inputfile, line ) ) {
            input.push_back(line);

        }
        cout << "All read";
        inputfile.close();
    }

    return input;
}


vector<std::string> readWithSeperator( const string& path, const char& seperator) {
    vector<string> input;
    string line;
    ifstream inputfile (path);
    if (inputfile.is_open()) {
        while( getline( inputfile, line, seperator) ) {
            input.push_back(line);

        }
        cout << "All read";
        inputfile.close();
    }

    return input;
}
