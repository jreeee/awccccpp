#ifndef NET_UTIL_HPP
#define NET_UTIL_HPP

#include <string>

namespace net_util {

    std::string get_awc_profile(std::string user);
    std::string post_request(std::string const& message, bool verbose);

};

#endif