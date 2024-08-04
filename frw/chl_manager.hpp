#ifndef CHL_MANAGER_HPP
#define CHL_MANAGER_HPP

#include <string>
#include <utility>
#include <vector>
#include "challenge.hpp"

class chl_manager {
  public:
    chl_manager(std::string user);
    std::vector<std::pair<int, int>> get_completed_challenge_posts();
  private:
    std::string user_;
    int user_id_;
};

#endif