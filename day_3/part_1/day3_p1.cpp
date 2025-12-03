#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "../../read_file_to_vec.cpp" 

using namespace std;


int main(int argc, char const *argv[])
{
    vector<string> joltage_input = readLineByLine("../input.txt");
    vector<int> voltages = {};
    int sum = {};

    for (size_t i = 0; i < joltage_input.size(); i++)
    {
        vector<char> highest_two_values = {};
        
        for (size_t k = 9; k > 0; k--)
        {
            string search_string = "";
            
            if (joltage_input[i].find(to_string(k)) != 18446744073709551615)
            {
                search_string.assign(joltage_input[i], joltage_input[i].find(to_string(k)) + 1, joltage_input[i].length());
                for (size_t l = 9; l > 0; l--)
                {
                    if (search_string.find(to_string(l)) != 18446744073709551615)
                    {
                        highest_two_values.push_back(joltage_input[i][joltage_input[i].find(to_string(k))]);
                        highest_two_values.push_back(search_string[search_string.find(to_string(l))]);
                    }
                    if (highest_two_values.size() == 2)  {break;}
                }
                if (highest_two_values.size() == 2)  {break;}
            }
            
        }
        
        string value = {};
        for (size_t ii = 0; ii < highest_two_values.size(); ii++)
        {
            //cout << highest_two_values[ii];
            value = value + highest_two_values[ii];
        }
        voltages.push_back(stoll(value));
        cout << '\t';
        
    }
    
    for (size_t i = 0; i < voltages.size(); i++)
    {
        sum += voltages[i];
    }
    
    cout << sum;

    return 0;
}
