#include "HrmlParser.hpp"
#include "../Utils/Utils.tpp"
#include <algorithm>

HrmlParser::HrmlParser(std::vector<std::string> hrml, std::vector<std::string> queries) noexcept
{
    for (auto& line : hrml)
    {
        auto splitted { Utils::split<3>(std::move(line), { '<', '>', '=' }) };
        if (*(splitted.begin()->begin()) != '/') m_tag_attributes.emplace_back(std::move(splitted));
    }

    for (auto& line : queries)
    {
        auto ignoreBefore { std::find(line.begin(), line.end(), '.') };

        if (ignoreBefore != line.end())
            line = { ignoreBefore + 1, line.end() };

        auto splitted { Utils::split(std::move(line), {}, '~') };
        m_tag_attributes.emplace_back(std::move(splitted));
    }
}

const std::vector<TagAttributes> &HrmlParser::tags() const noexcept
{
    return m_tag_attributes;
}

const std::vector<std::pair<std::string, std::string>> &HrmlParser::queries() const noexcept
{
    return m_queries;
}

std::vector<std::optional<std::string>> HrmlParser::execute_queries() const noexcept
{
    std::vector<std::optional<std::string>> results{};

    for (const auto& query : m_queries)
    {
        for (const auto& tag : m_tag_attributes)
        {
            auto begin { std::begin(tag.attributes()) };
            auto end { std::end(tag.attributes()) };

            auto find { std::find(begin, end, static_cast<std::pair<const std::string, std::string>>(query)) };

            if (find != end)
            {
                results.emplace_back(find->second);
                break;
            }
            else
            {
                results.emplace_back(std::nullopt);
            }
        }
    }

    return results;
}
