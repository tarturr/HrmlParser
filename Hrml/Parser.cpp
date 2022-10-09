#include <sstream>
#include <algorithm>
#include <iostream>
#include "Parser.hpp"

Parser::Parser(std::vector<std::string> hrml, std::vector<std::string> queries) noexcept
{
    std::size_t index{ 0 };
    for (const auto& line : hrml)
    {
        Tag tag{};
        std::istringstream stream{ line };

        std::string name;
        stream >> name;

        // If tag is opening
        if (name[1] != '/')
        {
            tag.name = name.substr(1);

            std::string attr, value;
            char equals;

            while ((stream >> attr >> equals >> value))
            {
                while (*(value.end() - 1) != '"' || *(value.end() - 1) != '>')
                {
                    // FIXME: value peut finir par un '>', ce qui peut faire une boucle infinie.
                    std::string part;
                    stream >> part;

                    value += " " + part;
                    std::cout << value << "|";
                }

                // If the value of the attribute ends by '>', it must be removed.
                tag.attributes.insert({ std::move(attr), std::move(*(value.end() - 1) == '>' ? value.substr(0, value.size() - 1) : value) });

                std::cout << "Ok" << std::endl;
            }

            // Si le tag actuel n'a pas de parent
            if (index == 0)
            {
                // On l'ajoute à la liste des tags "parents"
                m_tags.emplace_back(std::make_unique<Tag>(std::move(tag)));
            }
            else
            {
                // On l'ajoute à son tag parent
                m_tags[index]->children.emplace_back(std::make_unique<Tag>(std::move(tag)));
            }

            index++;
        }
        else
        {
            index--;
        }
    }

    std::cout << "HRML Parsing done" << std::endl;

    for (const auto& line : queries)
    {
        Query query{};

        auto begin{ std::begin(line) };
        auto end{ std::end(line) };
        auto separator{ std::find(begin, end, '.') };

        std::string current_tag_name{ begin, separator };
        auto tag{ tag_by_name(m_tags, current_tag_name) };

        while (separator != end)
        {
            query.final_tag = tag;

            begin = separator + 1;
            separator = std::find(begin, end, '.');

            current_tag_name = { begin, separator };
            tag = tag_by_name(query.final_tag->children, current_tag_name);
        }

        std::string attr{ std::find(line.begin(), line.end(), '~') + 1, line.end() };
        query.value_to_find = query.final_tag->attributes[attr];

        m_queries.emplace_back(std::make_unique<Query>(std::move(query)));
    }
}
