#include <iostream>
#include <string>
#include <vector>
#include <cctype> //for toupper(to upper case)
#include "at1.h"

//Contact_list class
//constructor
Contact_list::Contact_list(){
    head = nullptr;
    tail = nullptr;
}

//method
//add nodes to Contact_list
void Contact_list::add_end(Node* node){
    if(node == nullptr) {
        std::cout << "Please don't enter null input." << std::endl;
        return;
    }
    if(head == nullptr && tail == nullptr){
        tail = node;
        head = tail;
    }
    node->link_prev(tail);
    tail = node;
    
};

void Contact_list::add_front(Node* node){
    if (node == nullptr) {
        std::cout << "Please don't enter null input." << std::endl;
        return;
    }
 
    if(head == nullptr && tail == nullptr){
        head = node;
        tail = head;
    }
    node->link_next(head);
    head = node;
};

//print Contact_list
void Contact_list::print_list() {
    if (head==nullptr && tail==nullptr) {
        return;
    } else if (head!=nullptr && tail==nullptr) {
        head->print_node();
    } else if (head==nullptr && tail!=nullptr) {
        tail->print_node();
    } else {
        Node* curr;
        curr = head;
        while(curr != nullptr) {
            curr->print_node();
            curr = curr->next;
        }
        
    }
}

std::string Contact_list::get_search_name() {
    std::string target_name;
    std::cout << "Enter the name you want to search: " << std::endl;
    std::cin >> target_name;
    if(target_name == "") {
        std::cout << "please enter a valid name" << std::endl;
        std::cout << "Enter the name you want to search: " << std::endl;
        std::cin >> target_name;
    }
    return target_name;
}
void Contact_list::search_by_name(){
    std::string target_name = get_search_name();
    Node* curr = this->head;
    std::cout << "Search result: " << std::endl;
    while(curr->next != nullptr){

        if(curr->contact.get_name() == target_name){
            curr->print_node();
        }

        curr = curr->next;
        
    }

    if(curr->contact.get_name() == target_name){
        curr->print_node();
    }
    return;
}