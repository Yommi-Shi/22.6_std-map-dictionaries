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

void add_subscriber(std::map<std::string, std::string> &number_to_surname,
                    std::map<std::string, std::vector<std::string> > &surname_to_number) {
    std::cout << "Enter your phone number and last name in the format 69-70-30 Ivanov" << std::endl;
    std::string phone, last_name;
    std::cin >> phone >> last_name;
    number_to_surname.insert(std::make_pair(phone, last_name));
    if (surname_to_number.contains(last_name)) {
        surname_to_number[last_name].push_back(phone);
    } else {
        surname_to_number.insert(std::make_pair(last_name, std::vector<std::string>{phone}));
    }
}

void last_name_by_phone_number(std::map<std::string, std::string> &number_to_surname) {
    std::cout << "Enter a phone number to search for a last name:";
    std::string phone;
    std::cin >> phone;
    std::map<std::string, std::string>::iterator it = number_to_surname.find(phone);
    if (it != number_to_surname.end()) {
        std::cout << "Phone number owner " << it->first << " -> " << it->second << std::endl;
    } else {
        std::cout << "This phone number is not in the directory" << std::endl;
    }
}

void phone_number_by_last_name(std::map<std::string, std::vector<std::string>> &surname_to_number) {
    std::cout << "Enter last name to search for phone number:";
    std::string last_name;
    std::cin >> last_name;

    std::map<std::string, std::vector<std::string>>::iterator it = surname_to_number.find(last_name);
    if (it != surname_to_number.end()) {
        std::cout << "Subscribers have this phone number: ";
        for (std::string str: it->second) {
            std::cout << str << " ";
        }
        std::cout << std::endl;
    } else {
        std::cout << "This last name is not in the directory" << std::endl;
    }
}

int main() {
    std::cout << "===Telephone directory===" << std::endl;

    std::map<std::string, std::string> number_to_surname;
    std::map<std::string, std::vector<std::string>> surname_to_number;

    title();
    std::string cmd;
    while (std::cin >> cmd && cmd != "q") {
        if (cmd == "1") {
            add_subscriber(number_to_surname, surname_to_number);
        } else if (cmd == "2") {
            last_name_by_phone_number(number_to_surname);
        } else if (cmd == "3") {
            phone_number_by_last_name(surname_to_number);
        } else {
            std::cerr << "Invalid input" << std::endl;
        }
        title();
    }
}
