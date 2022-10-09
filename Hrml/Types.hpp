#ifndef HRMLPARSER_TYPES_HPP
#define HRMLPARSER_TYPES_HPP

#include <string>
#include <vector>
#include <unordered_map>
#include <memory>

struct Tag
{
    std::string name;
    std::unordered_map<std::string, std::string> attributes;
    std::vector<std::unique_ptr<Tag>> children;
};

struct Query
{
    Tag* final_tag;
    std::string value_to_find;
};

Tag* tag_by_name(const std::vector<std::unique_ptr<Tag>>& tags, const std::string &name) noexcept;

#endif //HRMLPARSER_TYPES_HPP
