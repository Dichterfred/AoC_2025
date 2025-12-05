#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "../../read_file_to_vec.cpp" 

using namespace std;

bool check_matrix(vector<string>& line_rolls, vector<int> position) {
    int adjacent_rolls = {};
    for (int i = position[0] - 1; i <= position[0] + 1; i++)
    {
        for (int j = position[1] - 1 ; j <= position[1] + 1; j++)
        {
            if (i != position[0] || j != position[1])
            {
                
                    if(line_rolls[i][j] == '@') {
                        adjacent_rolls ++;
                    }

            } 
            
        }
        
    }
    
    if (adjacent_rolls < 4) {
        return 1;
    } else {
        return 0;
    }
}

int main(int argc, char const *argv[])
{
    vector<string> line_rolls = readLineByLine("../input.txt");
    int accessable_rolls = {};
    vector<int> position = {0, 0};

    
    for (size_t i = 0; i < line_rolls.size(); i++)
    {
        for (size_t j = 0; j < line_rolls[i].length(); j++)
        {
            position[0] = i;
            position[1] = j;

            if(line_rolls[i][j] == '@') {
                if (check_matrix(line_rolls, position))
                {
                    accessable_rolls ++;
                    cout << position[0] << '\t' << position[1] << endl;
                }
            }
            
            
        }
        
    }
    
    cout << accessable_rolls;
    return 0;
}
