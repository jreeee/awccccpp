#include <iostream>

#include "../ext/nlohmann/json.hpp"
#include "../frw/chl_manager.hpp"
#include "../frw/str_util.hpp"
#include "../frw/net_util.hpp"


using json = nlohmann::json;

int main(int argc, char *argv[]) {
    // std::string user = "jreeee"; // idk what a "good" default value would be
    // if (argc > 1) {
    //     user = argv[1];
    // }
    // chl_manager manager = chl_manager(user);
    // std::vector<std::pair<int, int>> comments;
    // comments = manager.get_completed_challenge_posts();
    
    // for(auto i: comments) {
    //     std::cout << "https://anilist.co/forum/thread/" << i.first << "/comment/" << i.second << std::endl;
    // }
    
    //std::ifstream f("example.json");
    //json data = json::parse(f);

    std::string post = "{\"query\": \"query{Activity(id:26266744) { __typename ... on TextActivity{ text, replies { text }}}}\"}";

    std::string response = net_util::post_request(post,false);
    str_util::remove_char(response, '\\');
    
    std::string pattern = "https://anilist.co/forum/thread/";
    std::vector<int> posts = str_util::find_matching_pattern(response, pattern, false);

    const std::string addr = "https://anilist.co/forum/thread/";
    for(auto i: posts) {
        int thread_id = str_util::extract_digits_from_idx(response, i);
        std::pair<int, int> name = str_util::find_match_from_to_idx(response, i, '[', ']', true);
        std::cout << response.substr(name.first + 1, name.second-name.first-2) <<" - " << addr << thread_id << std::endl;
    }

}