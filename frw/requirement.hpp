#ifndef REQUIREMENT_HPP
#define REQUIREMENT_HPP

#include <string>
#include <vector>

class requirement {
  public:
    int number;
    std::string req_text;
    int entry_id;
    std::string start_date;
    std::string end_date;
    std::vector<std::string> added_info;

    std::string req_to_string();
    
};

#endif