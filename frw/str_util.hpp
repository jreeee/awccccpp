#ifndef STR_UTIL_HPP
#define STR_UTIL_HPP

#include <vector>
#include<string>

namespace str_util {
    std::vector<int> find_matching_pattern(std::string const& input, std::string const& pattern);
    int extract_digits_from_idx(std::string const& input, int index);
};

#endif