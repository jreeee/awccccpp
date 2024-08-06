#include "str_util.hpp"

#include <vector>

namespace str_util {
    std::vector<int> find_matching_pattern(std::string const& input, std::string const& pattern) {
        std::vector<int> indices;
        for(int i=0; i<(input.length() - pattern.length()); ++i) {
            if(input.at(i) != pattern.at(0)) { // early check
                continue;
            }
            if(input.substr(i, pattern.length()) == pattern) {
                indices.push_back(i);
                i += pattern.length();
            }
        }
        return indices;
    };

    int extract_digits_from_idx(std::string const& input, int index){
        int len = 0;
        while (isdigit(input.at(index+len))) {
            ++len;
        }
        return std::stoi(input.substr(index, len));
    };
}