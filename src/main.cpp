#include <iostream>
#include <istream>
#include <string>
#include <fstream>
#include <utility>
#include <vector>
#include "../ext/nlohmann/json.hpp"
#include "../frw/challenge.hpp"
#include "../ext/curlpp/include/curlpp/cURLpp.hpp"
#include "../ext/curlpp/include/curlpp/Easy.hpp"
#include "../ext/curlpp/include/curlpp/Options.hpp"

using json = nlohmann::json;

using namespace curlpp::options;

int main() {
    std::string profile;
    std::stringstream test;
    std::vector<std::pair<int, int>> comments;
    try {
        // curlpp::Easy myRequest;
        // myRequest.setOpt<curlpp::options::Url>("http://awc.moe/challenger/jreee");
        // myRequest.perform();
        test << curlpp::options::Url("https://awc.moe/challenger/jreeee");
    }
    catch(curlpp::RuntimeError & e) {
        std::cout << e.what() << std::endl;
        std::exit(1);
    }
    catch(curlpp::LogicError & e) {
        std::cout << e.what() << std::endl;
        std::exit(1);
    }
    profile = test.str();
    std::cout << profile.length() << std::endl;
    //std::cout << profile << std::endl;
    std::string match = "href=\"https://anilist.co/forum/thread/";
    for(int i=0; i<(profile.length() - match.length()); ++i) {
        if(profile.at(i) != match.at(0)) { // early check
            continue;
        }
        if(profile.substr(i, match.length()) == match) {
            i += match.length();
            int len = 0;
            while (isdigit(profile.at(i+len))) {
                ++len;
            }
            int thread = std::stoi(profile.substr(i, len));
            i += len + 9; // the nine comes from "/comment/" after the thread
            len = 0;
            while (isdigit(profile.at(i+len))) {
                ++len;
            }
            int comment = std::stoi(profile.substr(i, len));
            i += len;
            comments.push_back(std::make_pair(thread, comment));
        }
    }
    for(auto i: comments) {
        std::cout << "https://anilist.co/forum/thread/" << i.first << "/comment/" << i.second << std::endl;
    }
    //std::ifstream f("example.json");
    //json data = json::parse(f);
}