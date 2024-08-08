#include "net_util.hpp"

#include <string>
#include <sstream>

#include "../ext/curlpp/include/curlpp/Easy.hpp"
#include "../ext/curlpp/include/curlpp/Options.hpp"
#include "../ext/curlpp/include/curlpp/Exception.hpp"

namespace net_util {

    std::string get_awc_profile(std::string user) {
        
        std::stringstream test;
        std::vector<std::pair<int, int>> comments;
        try {
            test << curlpp::options::Url("https://awc.moe/challenger/" + user);
        }
        catch(curlpp::RuntimeError & e) {
            std::cout << e.what() << std::endl;
            std::exit(1);
        }
        catch(curlpp::LogicError & e) {
            std::cout << e.what() << std::endl;
            std::exit(1);
        }
        return test.str();
    };

    std::string post_request(std::string const& query, bool verbose) {
        // might need a option to return the request at some point
        try {
            std::ostringstream response;
            curlpp::Easy request;
            curlpp::options::WriteStream writestream(&response);

            request.setOpt(new curlpp::options::Verbose(verbose));
            request.setOpt(new curlpp::options::Url("https://graphql.anilist.co"));
            request.setOpt(new curlpp::options::HttpHeader({"Content-Type: application/json"}));
            request.setOpt(new curlpp::options::PostFields(query));
            request.setOpt(new curlpp::options::PostFieldSize(query.length()));
            request.setOpt(writestream);
            request.perform();
            return response.str();
        }
        catch(curlpp::RuntimeError & e) {
            std::cout << e.what() << std::endl;
            std::exit(1);
        }
        catch(curlpp::LogicError & e) {
            std::cout << e.what() << std::endl;
            std::exit(1);
        }
    };
} // end namespace net_util