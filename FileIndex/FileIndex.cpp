// FileIndex.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <filesystem>
#include <fstream>

namespace fs = std::filesystem;

int main()
{
    const fs::path directoryPath{ "Downloads" };

    for (const auto& entry : fs::directory_iterator(directoryPath))
    {
        if (fs::is_regular_file(entry))
        {
            std::cout << "File: " << entry.path() << std::endl;

            // Add your code to read the file here
            std::ifstream file(entry.path());
            if (file.is_open())
            {
                std::string line;
                while (std::getline(file, line))
                {
                    std::cout << line << std::endl;
                }
                file.close();
            }
            else
            {
                std::cerr << "Unable to open file: " << entry.path() << std::endl;
            }
        }
    }

    return 0;
}