#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;


int main(int argc, char const *argv[])
{
    vector<string> input = {};
    string line;

    ifstream inputfile ("input.txt");
    if (inputfile.is_open()) {
        while( getline( inputfile, line ) ) {
            input.push_back(line);

        }
        cout << "All read";
        inputfile.close();
    }

    int starting_num = { 50 };
    int timesCrossZero = {};

    /*
    L is minus 
    R is plus 
    */

    for (int i = 0; i < input.size() ; i ++) {
        char direction = input[i][0];
        int int_digits = {0};
        string test = {};
        
        for (int j = 1; j < input[i].length(); j++) {
            char ch_digits = {};
            ch_digits += input[i][j];
            test += ch_digits;
        }
        int_digits = stoi(test);

        if (direction == 'L') {
            starting_num -= int_digits %100;

            if (starting_num < 0) {
                starting_num = starting_num +100;
            }
            
        } else if (direction == 'R'){
            starting_num += int_digits % 100;
            if (starting_num > 100) {
                starting_num = starting_num - 100;
            }
            //timesCrossZero += (starting_num == 0) ? 1 : 0;
        }
        if (starting_num == 0 || starting_num == 100) {
            timesCrossZero ++;
        }
    }

    cout << timesCrossZero << endl << starting_num;
    
    

    return 0;
}
