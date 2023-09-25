#include <iostream>
#include <string>
#include <vector>
#include "at1.h"

hash_table::hash_table() : table(TABLE_SIZE) {}

int hash_table::hash(const std::string& key) {
    int hashValue = 0;
    for (char c : key) {
        hashValue += c;
    }
    return hashValue % TABLE_SIZE;
}

void hash_table::hash_insert(const std::string& key, const Contact& contact) {
    int index = hash(key);
    table[index].push_back(contact);
}



std::string hash_table::get_search_name() {
    std::string name = "";
    std::cout << "Enter the name you want to search: " << std::endl;
    std::cin >> name;
    if(name == "") {
        std::cout << "please enter a valid name" << std::endl;
        std::cout << "Enter the name you want to search: " << std::endl;
        std::cin >> name;
    }
    return name;
}
Contact hash_table::hash_search(std::string name) {
    name = get_search_name();
    int index = hash(name);
    for (Contact& contact : table[index]) {
        if (contact.get_name() == name) {
            contact.print_contact();
            return contact;
        }
    }
    
    return Contact("", ' ', -1);
}