#include <iostream>
#include <fstream>
#include "../ext/nlohmann/json.hpp"
#include "../frw/challenge.hpp"
#include "../ext/curlpp/include/curlpp/cURLpp.hpp"
#include "../ext/curlpp/include/utilspp/clone_ptr.hpp"
#include "../ext/curlpp/include/curlpp/Easy.hpp"
#include "../ext/curlpp/include/curlpp/Options.hpp"

using json = nlohmann::json;


int main() {
    std::cout << "hello world" << std::endl;
    std::ifstream f("example.json");
    json data = json::parse(f);
}