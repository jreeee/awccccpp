#include "chl_manager.hpp"
#include "net_util.cpp"
#include "str_util.cpp"
#include <string>
#include <utility>
#include <vector>

chl_manager::chl_manager(std::string user) : user_(user) {
};

std::vector<std::pair<int, int>> chl_manager::get_completed_challenge_posts() {
    std::vector<std::pair<int, int>> result;
    // todo check if user != ""
    std::string profile = net_util::get_awc_profile(user_);
    // todo check that profile != ""
    std::string pattern1 = "href=\"https://anilist.co/forum/thread/";
    std::string pattern2 = "/comment/";
    std::vector<int> matching_indices = str_util::find_matching_pattern(profile, pattern1);
    // make sure its greater 0
    for(int i: matching_indices) {
        int offset1 = i+pattern1.length();
        int challenge = str_util::extract_digits_from_idx(profile, offset1);
        int offset2 = offset1 + std::to_string(challenge).length() + pattern2.length();
        int comment = str_util::extract_digits_from_idx(profile, offset2);
        result.push_back(std::make_pair(challenge, comment));
    }
    return result;
};