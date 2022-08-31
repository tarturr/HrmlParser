#ifndef HRMLPARSER_HRMLPARSER_HPP
#define HRMLPARSER_HRMLPARSER_HPP


#include <string>
#include <vector>
#include <optional>
#include "TagAttributes.hpp"

class HrmlParser
{
public:
    explicit HrmlParser(std::vector<std::string> hrml, std::vector<std::string> queries) noexcept;

    [[nodiscard]] const std::vector<TagAttributes>& tags() const noexcept;
    [[nodiscard]] const std::vector<std::pair<std::string, std::string>>& queries() const noexcept;

    [[nodiscard]] std::vector<std::optional<std::string>> execute_queries() const noexcept;
private:
    std::vector<TagAttributes> m_tag_attributes;
    std::vector<std::pair<std::string, std::string>> m_queries;
};


#endif //HRMLPARSER_HRMLPARSER_HPP