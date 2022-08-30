#include <istream>
#include <iostream>
#include <algorithm>
#include "Utils.hpp"

namespace Utils
{
    std::vector<std::string> scan(int lines_count)
    {
        std::vector<std::string> lines{};

        for (int i = 0; i < lines_count; i++)
        {
            std::string line{};
            std::getline(std::cin >> std::ws, line);
            lines.emplace_back(std::move(line));
        }

        return lines;
    }
}