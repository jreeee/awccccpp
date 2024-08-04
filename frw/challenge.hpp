#ifndef CHALLENGE_HPP
#define CHALLENGE_HPP

#include "chl_post.hpp"
#include "chl_rules.hpp"

class challenge {
  public:
    int challenge_id;
    bool challenge_completed;
    std::vector<chl_post> posts;
    chl_rules rules;
};

#endif