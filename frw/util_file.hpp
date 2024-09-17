#ifndef UTIL_FILE_HPP
#define UTIL_FILE_HPP

#include <string>

namespace util {
namespace file {

    const std::string get_home_dir();
    // overload w username/id? -> check AL if exists
    void initial_setup(std::string const& home);
    void cleanup(std::string const& home);
    // reading in the config
    // caching stuff

} // end namespace file
} // end namespace util
#endif