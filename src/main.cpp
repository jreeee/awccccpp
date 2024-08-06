#include <iostream>

#include "../ext/nlohmann/json.hpp"
#include "../frw/chl_manager.hpp"
#include "../frw/str_util.hpp"

#include "../ext/curlpp/include/curlpp/cURLpp.hpp"
#include "../ext/curlpp/include/curlpp/Easy.hpp"
#include "../ext/curlpp/include/curlpp/Options.hpp"
#include "../ext/curlpp/include/curlpp/Exception.hpp"


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
    try {
        curlpp::Easy request;
        std::ostringstream os;

        request.setOpt(new curlpp::options::Url("https://graphql.anilist.co"));
        //request.setOpt(new curlpp::options::Verbose(true)); 
        
        std::list<std::string> header;
        header.push_back("Content-Type: application/json");
        std::string post = "{\"query\": \"query{Activity(id:26266744) { __typename ... on TextActivity{ text, replies { text }}}}\"}";
        std::string post_wo_comment = "{\"query\": \"query{Activity(id:26266744) { __typename ... on TextActivity{ text}}}\"}";
        request.setOpt(new curlpp::options::HttpHeader(header));
        request.setOpt(new curlpp::options::PostFields(post_wo_comment));
        request.setOpt(new curlpp::options::PostFieldSize(post_wo_comment.length()));
        curlpp::options::WriteStream ws(&os);
        request.setOpt(ws);
        request.perform();
        std::string pattern = "https:\\/\\/anilist.co\\/forum\\/thread\\/";
        std::vector<int> posts = str_util::find_matching_pattern(os.str(), pattern);

        const std::string addr = "https://anilist.co/forum/thread/";
        for(auto i: posts) {
            int thread_id = str_util::extract_digits_from_idx(os.str(), i+pattern.length());
            std::cout << addr << thread_id << std::endl;
        }

    }
    catch ( curlpp::LogicError & e ) {
        std::cout << e.what() << std::endl;
    }
    catch ( curlpp::RuntimeError & e ) {
        std::cout << e.what() << std::endl;
    }

    return EXIT_SUCCESS;

    //std::ifstream f("example.json");
    //json data = json::parse(f);
}