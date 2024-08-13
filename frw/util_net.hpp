#ifndef UTIL_NET_HPP
#define UTIL_NET_HPP

#include <string>

namespace util {
namespace net {

    std::string get_awc_profile(std::string user);
    std::string post_request(std::string const& message, bool verbose);

}; // end namespace net
} //end namespace util

#endif