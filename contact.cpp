#include <iostream>
#include <string>
#include <vector>
#include <cctype> //for toupper(to upper case)
#include "at1.h"

//Contact class
//get set
std::string Contact::get_name() const {
    return name;
}
void Contact::set_name(std::string person_name) {
    name = person_name;
}

char Contact::get_gender() const {
    return gender;
}
void Contact::set_gender(char person_gender) {
    gender = person_gender;
}

int Contact::get_age() const {
    return age;
}
void Contact::set_age(int person_age) {
    age = person_age;
}

//constructor
Contact::Contact(std::string person_name, char person_gender, int person_age) : name(person_name), gender(person_gender), age(person_age) {}

//method
void Contact::print_contact() {
        std::cout << "name: " << get_name() << std::endl;
        std::cout << "gender: " << get_gender() << std::endl;
        std::cout << "age: " << get_age() << std::endl;
}

















