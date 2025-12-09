#include <iostream>
#include <fstream>
#include <string>
#include <vector>

#include "../../read_file_to_vec.cpp"

using namespace std;


int main(int argc, char const *argv[])
{
    vector<string> input = readLineByLine("../input.txt");
    string line;
    int starting_num = { 50 };
    int timesCrossZero = 0;
    /*
    L is minus 
    R is plus 
    */

    for (int i = 0; i < input.size() ; i ++) {
        char direction = input[i][0];
        int int_digits = {0};
        string string_digits = {};
        
        string_digits.assign(input[i], 1, input[i].length());
        int_digits = stoll(string_digits); 


        if (direction == 'L') {
            if (starting_num != 0 && starting_num != 100)
            {
                starting_num -= int_digits;
                while (starting_num < 0)
                {
                    starting_num += 100;
                    timesCrossZero ++;
                }
            } else 
            {
                starting_num -= int_digits;
                while (starting_num < 0)
                {
                    starting_num += 100;
                }
            }
        
        } else if (direction == 'R'){
            if (starting_num != 0 && starting_num != 100)
            {
                starting_num += int_digits;
                while (starting_num > 100)
                {
                    starting_num -= 100;
                    timesCrossZero ++;
                }
            } else 
            {
                starting_num += int_digits;
                while (starting_num > 100)
                {
                    starting_num -= 100;
                }
            }
            
        }
        if (starting_num == 100 || starting_num == 0) 
        {
            timesCrossZero ++;
        }
        
        

    }
    

    cout << timesCrossZero << endl << starting_num;
    
    

    return 0;
}
