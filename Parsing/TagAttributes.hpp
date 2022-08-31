#ifndef HRMLPARSER_TAGATTRIBUTES_HPP
#define HRMLPARSER_TAGATTRIBUTES_HPP


#include <vector>
#include <string>
#include <unordered_map>

class TagAttributes
{
public:
    explicit TagAttributes(std::vector<std::string> hrml) noexcept;

    const std::string& name() const noexcept;
    std::unordered_map<std::string, std::string> attributes() const noexcept;
private:
    std::string m_name;
    std::unordered_map<std::string, std::string> m_attributes;
};


#endif //HRMLPARSER_TAGATTRIBUTES_HPP