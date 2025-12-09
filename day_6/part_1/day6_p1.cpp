#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "../../read_file_to_vec.cpp" 

using namespace std;


int main(int argc, char const *argv[])
{
    vector<vector<string>> lines = readWithSeperatorInNestedVec("../input.txt", ' ');

    long sumSum = 0;

    cout << lines[0][1000];

    for (int i = 0; i < lines[0].size(); i++)
    {
        long sum = 0;
        long prod = 1;

        for (int j = 0; j < lines.size() - 1; j++)
        {
            string operat = lines[lines.size() - 1][i];

            if (operat == "+")
            {
                sum += stoll(lines[j][i]);
            }
            if (operat == "*")
            {
                prod *= stoll(lines[j][i]);
            }
        }
        if (prod != 1)
        {
            sumSum += prod;
        } 
        sumSum += sum;
        
    }
    
    
    cout << sumSum;

    return 0;
}
