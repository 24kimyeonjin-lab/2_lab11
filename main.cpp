#include <iostream>
#include "dayOfYear.h"
#include <string>
#include <fstream>
#include <vector>

namespace KimYeonjin2693058
{
    void readWriteDayOfYearDataFile(std::ifstream& fin, std::ofstream& fout)
    {
       std::vector<dayOfYear> v;

            std::streambuf* origBuf{ std::cout.rdbuf() };
            std::cout.rdbuf(nullptr);
            
            dayOfYear d;
            while(fin >> d)
            {
                v.push_back(d);
            }

            std::cout.rdbuf(origBuf);

            for (const auto& vi : v)
                fout << vi;
    }
}

int main()
{
    using namespace KimYeonjin2693058;
    dayOfYear d; 

    std::ifstream fin{ "dayOfYearData.txt" };
    if (fin.fail())
    {
        std::cout << "Input file opening failed.\n";
        std::exit(1);
    }
    std::streambuf* origBuf{ std::cout.rdbuf() };
    std::cout.rdbuf(nullptr);
    fin >> d;
    std::cout.rdbuf(origBuf);

    std::ofstream fout{ "out.txt"};
    // std::string fileName;
    // std::cout << "Enter output file name: ";
    // std::cin >> fileName;
    // fileName = fileName + ".txt";
    // fout.open(fileName);

    if(fout.fail())
    {
        std::cout << "Output file opening failed.\n";
        std::exit(1);
    }

    readWriteDayOfYearDataFile(fin, fout);

    fin.close();
    fout.close();

   
    return 0;
}

