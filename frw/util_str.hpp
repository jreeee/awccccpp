#ifndef UTIL_STR_HPP
#define UTIL_STR_HPP

#include <vector>
#include<string>

namespace util {
namespace str {
    void remove_char(std::string & str, char remove);
    std::vector<int> find_matching_pattern(std::string const& input, std::string const& pattern, bool incl_match);
    int extract_digits_from_idx(std::string const& input, int index);
    std::pair<int, int> find_match_from_to_idx(std::string const& input, int index, char begin, char end, bool reverse);
}; // end namespace str
} // end namespace util
#endif