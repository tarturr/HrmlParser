#ifndef HRMLPARSER_TAGATTRIBUTES_HPP
#define HRMLPARSER_TAGATTRIBUTES_HPP


#include <vector>
#include <string>
#include <unordered_map>

class TagAttributes
{
public:
    TagAttributes(std::vector<std::string> hrml, std::vector<std::string> queries) noexcept;
private:
    std::string m_name;
    std::unordered_map<std::string, std::string> m_attributes;
};


#endif //HRMLPARSER_TAGATTRIBUTES_HPP
