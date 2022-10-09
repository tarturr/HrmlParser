#ifndef HRMLPARSER_PARSER_HPP
#define HRMLPARSER_PARSER_HPP


#include <string>
#include <vector>
#include <memory>
#include "Types.hpp"

class Parser
{
public:
    Parser() = delete;

    Parser(const Parser&) = delete;
    Parser(Parser&&) = delete;

    Parser& operator=(const Parser&) = delete;
    Parser& operator=(Parser&&) = delete;

    Parser(std::vector<std::string> hrml, std::vector<std::string> queries) noexcept;
private:
    std::vector<std::unique_ptr<Tag>> m_tags;
    std::vector<std::unique_ptr<Query>> m_queries;
};


#endif //HRMLPARSER_PARSER_HPP
