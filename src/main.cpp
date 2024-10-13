#include <ctime>
#include <iostream>
#include <ostream>
#include <string>

#include "../ext/nlohmann/json.hpp"
#include "../frw/chl_manager.hpp"
#include "../frw/util_str.hpp"
#include "../frw/util_net.hpp"
#include "../frw/util_type.hpp"
#include "../frw/util_file.hpp"


using json = nlohmann::json;

int main(int argc, char *argv[]) {
    int test = 7;

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
        auto challenge_name_idx = util::str::find_match_from_to_idx(response, 0,  "~~~__", "__~~~", false);
        std::string title = response.substr(challenge_name_idx.first, challenge_name_idx.second-challenge_name_idx.first);
    }

    //challenge post stuff
    if (test == 7) {
        int thread_id = 77142;
        int post_id = 2736880;
        std::string post_url = "https://anilist.co/forum/thread/"+ std::to_string(thread_id) + "/comment/" + std::to_string(post_id);
        std::string thread = "{\"query\": \"query{Thread(id: " + std::to_string(thread_id) + ") { body }}\"}";
        std::string response1 = util::net::post_request(thread,false);
        auto challenge_name_idx = util::str::find_match_from_to_idx(response1, 0,  "~~~__", "__~~~", false);
        std::string title = response1.substr(challenge_name_idx.first, challenge_name_idx.second-challenge_name_idx.first);

        std::string post = "{\"query\": \"query{ThreadComment(id: " + std::to_string(post_id) + ") { comment, createdAt }}\"}";
        std::string response2 = util::net::post_request(post,false);
        json json_post = nlohmann::json::parse(response2);
        std::cout << title << std::endl;
        std::cout << json_post["data"]["ThreadComment"][0]["comment"] <<std::endl;
        time_t t = json_post["data"]["ThreadComment"][0]["createdAt"];
        struct tm *tm = localtime(&t);
        char date[12];
        strftime(date, sizeof(date), "%Y-%m-%d", tm);
        std::cout <<date <<std::endl;
        // pattern search <hr> and append all occurence indices into a vector.
        // susbstr1 = head -> start/end date, legend, special/custom stuff
        // substr (i to i-1) = body -> reqs -> req, entry, start/finish date, [comments]
        // substr n = footer -> optional, anything goes
    }
}