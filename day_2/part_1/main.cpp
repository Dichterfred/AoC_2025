#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "../../read_file_to_vec.cpp" 

using namespace std;

int main(int argc, char const *argv[])
{
    string path = "../input.txt";
    auto input = readWithSeperator(path, ',');
    long sum = {};



    for (int i = 0; i < input.size(); i++)
    {
        string lower_bound = {};
        string upper_bound = {};
        vector<int> invalidIDs = {};

        lower_bound.assign(input[i], 0, input[i].find_first_of('-'));
        upper_bound.assign(input[i], input[i].find_first_of('-') + 1, input[i].size());

        try
        {
            for ( long j = stoll(lower_bound); j < stoll(upper_bound); j++)
            {
                string number_str = to_string(j);
                string first_half = "";
                string second_half = "";

                first_half = first_half.assign(
                    number_str, 
                    0, 
                    number_str.length() / 2
                );
                
                second_half.assign(
                    number_str,
                    number_str.length() / 2,
                    number_str.length()
                );
                if (first_half == second_half) {
                    sum += stoll(number_str);
                }
            }
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n' << lower_bound << '\t' << upper_bound <<endl;
            
            
        }
        
        
        
        
    }
    
    
    cout << sum;
    return 0;
}


