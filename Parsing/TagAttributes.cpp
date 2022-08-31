#include "TagAttributes.hpp"
#include "../Utils/Utils.tpp"

TagAttributes::TagAttributes(std::vector<std::string> hrml) noexcept
        : m_name(hrml[0])
{
    for (int i = 1; i < hrml.size(); i++)
    {
        m_attributes.insert({ hrml[i], hrml[++i] });
    }
}

const std::string &TagAttributes::name() const noexcept
{
    return m_name;
}

std::unordered_map<std::string, std::string> TagAttributes::attributes() const noexcept
{
    return m_attributes;
}
