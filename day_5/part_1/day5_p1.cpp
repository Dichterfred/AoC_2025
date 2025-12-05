#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "../../read_file_to_vec.cpp" 

using namespace std;

int main(int argc, char const *argv[])
{
    vector<string> id_ranges = readUntilEmptyString("../input.txt");
    vector<string> available_ids = readWithSeperatorFromStartLine("../input.txt", id_ranges.size());
    cout << endl;
    int fresh_ingr = 0;

    for (size_t i = 0; i < available_ids.size(); i++)
    {
        for (size_t j = 0; j < id_ranges.size(); j++)
        {
            vector<string> range_j = {"0", "0"};
            range_j[0].assign(id_ranges[j], 0, id_ranges[j].find('-'));
            range_j[1].assign(id_ranges[j], id_ranges[j].find('-') + 1, id_ranges[j].length());

            // cout << range_j[0] << '\t' << range_j[1] << endl;

            if (stoll(available_ids[i]) >= stoll(range_j[0]) && stoll(available_ids[i]) <= stoll(range_j[1])) 
            {
                fresh_ingr ++;
                break;
            }

        }
    }
    
    cout << fresh_ingr;
    return 0;
}
