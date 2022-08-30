#include <string>
#include <vector>
#include <array>
#include <algorithm>
#include <sstream>

namespace Utils
{
    template<size_t N>
    std::string clean(const std::string& str, const std::array<char, N>& to_clean = {})
    {
        if constexpr (N > 0)
        {
            std::ostringstream ss;
            bool was_space { false };

            for (auto const& c : str)
            {
                if (std::find(to_clean.begin(), to_clean.end(), c) == to_clean.end())
                {
                    if (c == ' ')
                    {
                        if (!was_space)
                            ss << c;
                    }
                    else
                        ss << c;

                    was_space = c == ' ';
                }
            }

            return ss.str();
        }

        return "";
    }

    template<std::size_t N>
    std::vector<std::string> split(std::string str, const std::array<char, N>& ignore = {}, char delimiter = ' ') noexcept
    {
        if constexpr (N > 0)
            str = clean<N>(str, ignore);

        auto begin { std::begin(str) };
        auto end { std::end(str) };
        std::vector<std::string> splitted{};

        auto find { std::find(begin, end, delimiter) };

        while (find != end)
        {
            splitted.emplace_back(begin, find);

            begin = find + 1;
            find = std::find(begin, end, delimiter);
        }

        splitted.emplace_back(begin, end);

        return splitted;
    }
}
