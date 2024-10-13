#include <iostream>

#include "../ext/nlohmann/json.hpp"
#include "../frw/chl_manager.hpp"
#include "../frw/util_str.hpp"
#include "../frw/util_net.hpp"
#include "../frw/util_type.hpp"
#include "../frw/util_file.hpp"


using json = nlohmann::json;

int main(int argc, char *argv[]) {
    int test = 6;

    if (test == 1) {
        std::string user = "jreeee"; // idk what a "good" default value would be
        if (argc > 1) {
            user = argv[1];
        }
        chl_manager manager = chl_manager(user);
        std::vector<std::pair<int, int>> comments;
        comments = manager.get_completed_challenge_posts();
        
        for(auto i: comments) {
            std::cout << "https://anilist.co/forum/thread/" << i.first << "/comment/" << i.second << std::endl;
        }
    }

    // if (test == 2) {
    //     std::ifstream f("example.json");
    //     json data = json::parse(f);
    // }

    if (test == 3) {
        std::string post = "{\"query\": \"query{Activity(id:26266744) { __typename ... on TextActivity{ text, replies { text }}}}\"}";

        std::string response = util::net::post_request(post,false);
        util::str::remove_char(response, '\\');
        
        std::string pattern = "https://anilist.co/forum/thread/";
        std::vector<int> posts = util::str::find_matching_pattern(response, pattern, false);

        const std::string addr = "https://anilist.co/forum/thread/";
        for(auto i: posts) {
            int thread_id = util::str::extract_digits_from_idx(response, i);
            std::pair<int, int> name = util::str::find_match_from_to_idx(response, i, "[", "]", false);
            std::cout << response.substr(name.first + 1, name.second-name.first-2) <<" - " << addr << thread_id << std::endl;
        }
    }

    if (test == 4) {
        const auto tags = util::type::MediaTag::getInstance();
        for (auto const& i : tags.tags) {
            std::cout << "id: " << i.id << ", name: " << i.name << ", adult:" << i.is_adult << ", category: " << tags.categories.at(i.category_index) << std::endl;
        }
        std::cout << tags.categories.size() << ", " << tags.tags.size() << std::endl;
    }

    if (test == 5) {
        auto home = util::file::get_home_dir();
        std::cout << home << std::endl;
        util::file::initial_setup(home);
    }

    if (test == 6) {
        std::string thread = "{\"query\": \"query{Thread(id:76502) { body }}\"}";
        std::string response = util::net::post_request(thread,false);
        auto a = util::str::find_match_from_to_idx(response, 0,  "~~~__", "__~~~", false);
        std::cout << response.substr(a.first, a.second-a.first)<< std::endl;
    }
}