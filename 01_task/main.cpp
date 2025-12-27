#include <iostream>
#include <map>
#include <string>
#include <vector>

void title() {
    std::cout << "Enter the command:\n"
            "\t1 - add the subscriber\'s phone number and last name to the directory;\n"
            "\t2 - find out the subscriber's last name by phone number;\n"
            "\t3 - find out the subscriber's phone number by last name;\n"
            "\tq - exit" << std::endl;
    std::cout << "->";
}

void add_subscriber(std::map<std::string, std::string> &phone_direct) {
    std::cout << "Enter your phone number and last name in the format 69-70-30 Ivanov" << std::endl;
    std::string phone, last_name;
    std::cin >> phone >> last_name;
    phone_direct.insert(std::make_pair(phone, last_name));
}

void last_name_by_phone_number(std::map<std::string, std::string> &phone_direct) {
    std::cout << "Enter a phone number to search for a last name:";
    std::string phone;
    std::cin >> phone;
    std::map<std::string, std::string>::iterator it = phone_direct.find(phone);
    if (it != phone_direct.end()) {
        std::cout << "Phone number owner " << it->first << " -> " << it->second << std::endl;
    } else {
        std::cout << "This phone number is not in the directory" << std::endl;
    }
}

void phone_number_by_last_name(std::map<std::string, std::string> &phone_direct) {
    std::vector<std::string> list_name;
    std::cout << "Enter last name to search for phone number:";
    std::string last_name;
    std::cin >> last_name;
    for (std::map<std::string, std::string>::iterator it = phone_direct.begin(); it != phone_direct.end(); ++it) {
        if (it->second == last_name) {
            list_name.push_back(it->first);
        }
    }
    if (list_name.empty()) {
        std::cout << "This last name is not in the directory" << std::endl;
    } else {
        std::cout << "Subscribers have this phone number: ";
        for (std::string name: list_name) {
            std::cout << name << " ";
        }
        std::cout << std::endl;
    }
}

int main() {
    std::cout << "===Telephone directory===" << std::endl;

    std::map<std::string, std::string> phone_direct;

    title();
    std::string cmd;
    while (std::cin >> cmd && cmd != "q") {
        if (cmd == "1") {
            add_subscriber(phone_direct);
        } else if (cmd == "2") {
            last_name_by_phone_number(phone_direct);
        } else if (cmd == "3") {
            phone_number_by_last_name(phone_direct);
        } else {
            std::cerr << "Invalid input" << std::endl;
        }
        title();
    }
}
