#include <iostream>
#include "Utils/Utils.hpp"
#include "Hrml/Parser.hpp"

int main()
{
    /*int hrmlLines, queriesLines;
    std::cin >> hrmlLines >> queriesLines;

    auto lines { Utils::scan(hrmlLines) };
    auto queries { Utils::scan(queriesLines) };*/

    std::vector<std::string> hrml{};
    hrml.emplace_back(R"(<first element = "super value" element2 = "really cool value2">)");
    hrml.emplace_back(R"(<second foo = "foo bar" bar = "foo bar haha">)");

    std::vector<std::string> queries{};

    Parser parser{ std::move(hrml), std::move(queries) };

    return 0;
}