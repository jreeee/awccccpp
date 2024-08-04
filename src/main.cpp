#include <iostream>

#include "../ext/nlohmann/json.hpp"
#include "../frw/chl_manager.hpp"

using json = nlohmann::json;

int main(int argc, char *argv[]) {
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
    //std::ifstream f("example.json");
    //json data = json::parse(f);
}