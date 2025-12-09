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
        cout << "All read" << endl;
        inputfile.close();
    }

    return input;
}


vector<std::string> readWithSeperator( const string& path, const char& seperator) {
    vector<string> input;
    string line;
    ifstream inputfile (path);
    if (inputfile.is_open()) {
        while( getline(inputfile, line, seperator)) {
            if (line.size() != 0 && line != "\n")
            {
                input.push_back(line);
            }

        }
        cout << "All read" << endl;
        inputfile.close();
    }

    return input;
}

vector<vector<std::string>> readWithSeperatorInNestedVec( const string& path, const char& seperator) {
    vector<vector<std::string>> input = {};
    std::string line;
    ifstream inputfile (path);
    if (inputfile.is_open()) {
        int i = 0;
        while( getline(inputfile, line, seperator)) {
            if (line == "\n")
            {
                i ++;
            } else
            {
                if(input.size() <= i) {
                    input.push_back({});
                }
                if (line.size() != 0)
                {
                    input[i].push_back(line);
                }
            }
        }
        cout << "All read" << endl;
        inputfile.close();
    }

    return input;
}

vector<std::string> readUntilEmptyString(const string& path) {
    vector<string> input;
    string line;
    ifstream inputfile (path);
    if (inputfile.is_open()) {
        while( getline(inputfile, line)) {
            if (!(line.size()))
            {
                break;
            }
            
            input.push_back(line);

        }
        cout << "All read" << endl;
        inputfile.close();
    }

    return input;
}

vector<std::string> readWithSeperatorFromStartLine(const string& path, const int& startline) {
    vector<string> input;
    string line;
    ifstream inputfile (path);
    int deleted = 0;
    if (inputfile.is_open()) {
        while( getline(inputfile, line)) {
            if (input.size() == startline + 1 && deleted == 0) {
                input = {};
                deleted ++;
            }
            
            input.push_back(line);

        }

        
        cout << "All read" << endl;
        inputfile.close();
    }

    return input;
}
