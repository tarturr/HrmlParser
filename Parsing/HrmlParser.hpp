#ifndef HRMLPARSER_HRMLPARSER_HPP
#define HRMLPARSER_HRMLPARSER_HPP


#include <string>
#include <vector>
#include "TagAttributes.hpp"

class HrmlParser
{
public:
    HrmlParser(std::vector<std::string> hrml, std::vector<std::string> queries) noexcept;
private:
    std::vector<TagAttributes> m_tag_attributes;
};


#endif //HRMLPARSER_HRMLPARSER_HPP
