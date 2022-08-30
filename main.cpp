#include <iostream>
#include "Utils/Utils.hpp"

int main()
{
    int hrmlLines, queriesLines;
    std::cin >> hrmlLines >> queriesLines;

    auto lines { Utils::scan(hrmlLines) };
    auto queries { Utils::scan(queriesLines) };

    return 0;
}
