#ifndef CHL_POST_HPP
#define CHL_POST_HPP


#include "requirement.hpp"
#include <string>


class chl_post {
  public:
    // general info
    // like anilist.co/forum/thread/challenge_id/comment/post_id
    int challenge_id;
    int post_id;
    // post 
    std::vector<requirement> reqs;
    std::string full_challenge_post;
    bool card_view;
    std::string post_creation_date;
    std::string post_end_date;
    bool post_completed;

    // somehow deal with the added comments
};

#endif