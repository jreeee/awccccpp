#include "util_str.hpp"

#include <string>
#include <utility>
#include <vector>
#include <algorithm>

namespace util {
namespace str {
    // takes the string that should be searched and returns all indicies at which a match occurs
    // if "include_match" is TRUE the index starts at the first matching char
    // if "include_match" is FALSE the index starts at the first char AFTER the matching pattern
    std::vector<int> find_matching_pattern(std::string const& input, std::string const& pattern, bool include_match) {
        std::vector<int> indices;
        for(int i=0; i<(input.length() - pattern.length()); ++i) {
            if(input.at(i) != pattern.at(0)) { // early check
                continue;
            }
            if(input.substr(i, pattern.length()) == pattern) {
                if(include_match) {
                    indices.push_back(i);
                }
                i += pattern.length();
                if(!include_match) {
                    indices.push_back(i);
                }
            }
        }
        return indices;
    };

    // iterates over a string and terminates when a non-digit is encountered, returning the int read in
    // if there is no number to begin with it returns "-1" which is a number it cant read in (as opposed to "0")
    int extract_digits_from_idx(std::string const& input, int index){
        int len = 0;
        while (isdigit(input.at(index+len))) {
            ++len;
        }
        if(len == 0) {
            return -1;
        }
        return std::stoi(input.substr(index, len));
    };

    // iterates over a string starting at a specified index to match two chars in order, like '[', ']'
    // depending on if reverse is set it either iterates to the end of the string or to the beginning.
    // the pattern stays the same for both and does not have to be swapped to facilitate the process
    std::pair<int, int> find_match_from_to_idx(std::string const& input, int idx, std::string const& begin, std::string const& end, bool reverse) {
        int begin_idx = -1;
        int end_idx = -1;


        if (!reverse) {
            for(int i=idx; i<input.length(); ++i) {
                if(begin_idx < 0 && input.substr(i, begin.length()) == begin) {
                    if (begin.length() == 1) {
                        begin_idx = i;
                    }
                    else {
                        begin_idx = i + begin.length();
                    }
                    continue;
                }
                if(begin_idx >= 0 && input.substr(i, end.length()) == end) {
                    if (end.length() == 1) {
                        end_idx = i+1;
                    }
                    else {
                        end_idx = i;
                    }
                    return std::make_pair(begin_idx, end_idx);
                }
            }
        }
        else {
            for(int i=idx; i>begin.length(); --i) {
                if(end_idx < 0 && input.substr(i, end.length()) == end) {
                    if (end.length() == 1) {
                        end_idx = i+1;
                    }
                    else {
                        end_idx = i;
                    }
                    continue;
                }
                if(end_idx >= 0 && input.substr(i, begin.length()) == begin) {
                    if (begin.length() == 1) {
                        return std::make_pair(i, end_idx);
                    }
                    else {
                        return std::make_pair(i + begin.length(), end_idx);
                    }
                }
            }
        }
        return std::make_pair(-1, -1);
    };

    void remove_char(std::string &str, char remove) {
        str.erase(std::remove(str.begin(), str.end(), remove), str.end());
    }
} //end of namespace str
} // end namespace util