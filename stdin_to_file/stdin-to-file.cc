#include <fstream>
#include <iostream>
#include <string>

using namespace std;

void stdin_to_file()
{
    ofstream myfile("file.out");
    if (myfile.is_open())
    {
        std::string line;
        while (std::cin >> line)
        {
            myfile << line << '\n';
        }
    }
    else
    {
        cout << "can't open file";
    }
}
