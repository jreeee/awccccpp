#include "util_type.hpp"
#include "util_net.hpp"

#include "../ext/nlohmann/json.hpp"
#include <iostream>

namespace util{
namespace type {

MediaTag::MediaTag() {
    tags.reserve(500);
    categories.reserve(50);
    // planned: 
    // 1: check if file exists to get json from
    // 2: update if forced or nonexistent
    std::string query = "{ \"query\": \"query{MediaTagCollection{ id, name, category, isAdult }}\"}";
    auto res = util::net::post_request(query, false);

    // 
    nlohmann::json json = nlohmann::json::parse(res);

    for (auto& el : json["data"]["MediaTagCollection"].items()) {
        int cat_index = checkCategory(el.value()["category"]);
        tags.push_back({el.value()["id"], el.value()["name"], cat_index, el.value()["isAdult"]});
    }
}

int MediaTag::checkCategory(std::string const& category) {
    for (int i=0; i<categories.size(); ++i) {
        if (category == categories.at(i)) {
            return i;
        }
    }
    categories.push_back(category);
    return categories.size()-1;
}

MediaTag& MediaTag::getInstance() {
    static MediaTag instance;
    return instance;
}

}
}