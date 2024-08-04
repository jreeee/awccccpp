#include <string>
#include <sstream>

#include "../ext/curlpp/include/curlpp/cURLpp.hpp"
#include "../ext/curlpp/include/curlpp/Easy.hpp"
#include "../ext/curlpp/include/curlpp/Options.hpp"

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
}