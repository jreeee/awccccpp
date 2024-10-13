#include "util_file.hpp"
#include <cstdlib>
#include <filesystem>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <string>

#include "../ext/nlohmann/json.hpp"

#if not BUILD_WINDOWS
#include <pwd.h>
#include <unistd.h>
#else
//idk
#endif

namespace util {
namespace file {

const std::string get_home_dir() {

    std::string env_pwd;

#if BUILD_WINDOWS

    env_pwd = getenv("USERPROFILE");
    
    if (env_pwd == "") {
        env_pwd = getenv("HOMEDRIVE");
        env_pwd += getenv("HOMEPATH");
    }

#else

    auto pwd = getpwuid(getuid());
    
    if (pwd) {
        return pwd->pw_dir;
    }
    env_pwd = getenv("HOME");
    
#endif
    if (env_pwd == "") {
        std::cerr << "couldn't find home directory, exiting" << std::endl;
        std::exit(1);
    }
    return env_pwd;
}

void initial_setup(std::string const& home) {
    std::string cfg = ".config";
    std::string cache = ".cache";
    std::filesystem::current_path(home);
    // base dirs
    if (!std::filesystem::exists(cfg)) {
        std::filesystem::create_directory(cfg);
    }
    if (!std::filesystem::exists(cache)) {
        std::filesystem::create_directory(cache);
    }
    if (!std::filesystem::exists(cfg + "/aw4cpp")) {
        std::filesystem::create_directory(cfg + "/aw4cpp");
    }
    if (!std::filesystem::exists(cache + "/aw4cpp")) {
        std::filesystem::create_directory(cache + "/aw4cpp");
    }
    // files
    // set up a proper cfg to copy?
    nlohmann::json usr_cfg = {{"user", ""}};
    std::ofstream os(cfg + "/aw4cpp/awc4pp.cfg");
    os << std::setw(4) << usr_cfg << std::endl;
}

void cleanup(const std::string &home) {
    // mb have the user confirm that this is the right dir
    std::filesystem::current_path(home);
    std::filesystem::remove_all(".config/aw4cpp");
    std::filesystem::remove_all(".cache/aw4cpp");
}

} // end namespace file
} // end namespace util