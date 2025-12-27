#include <chrono>
#include <iostream>
#include <string>
#include <map>

int main() {
    std::cout << "Registry" << std::endl;

    std::map<std::string, std::string> registry;
    int count = 0;

    while (true) {
        std::cout << "<-";
        std::string last_name;
        std::cin >> last_name;
        if (last_name == "Next") {
            std::map<std::string, std::string>::iterator it = registry.begin();
            std::cout << "->" << it->second << std::endl;
            registry.erase(it->first);
        } else {
            registry.insert(std::make_pair(last_name + std::to_string(count), last_name));
            count++;
        }
    }
}
