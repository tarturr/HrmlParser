#include "Types.hpp"

Tag* tag_by_name(const std::vector<std::unique_ptr<Tag>>& tags, const std::string &name) noexcept
{
    for (const auto& tag : tags)
    {
        if (tag->name == name)
            return tag.get();
    }

    return nullptr;
}