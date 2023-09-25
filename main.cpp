#include <iostream>
#include <string>
#include <vector>
#include "at1.h"

int main(){
    Contact contact1("rachel", 'F', 36);
    Contact contact2("phoebe", 'F', 35);
    Contact contact3("monica", 'F', 34);
    Contact contact4("ross", 'M', 33);
    Contact contact5("chandler", 'M', 32);
    Contact contact6("joey", 'M', 31);

    Node* node1 = new Node(contact1);
    Node* node2 = new Node(contact2);
    Node* node3 = new Node(contact3);
    Node* node4 = new Node(contact4);
    Node* node5 = new Node(contact5);
    Node* node6 = new Node(contact6);




    int choice;
    Contact_list* list = nullptr; // 在 switch 之前声明 list

    std::string name = "";
    int age = -1;
    char gender = ' ';
    Contact new_contact = Contact(name, gender, age);
    Node* new_node = nullptr;
    std::string target_name = "";
    Tree* tree = new Tree; // 在 switch 之前声明 tree

    hash_table contacts_hash_table;




     do{
        std::cout << "Menu:\n";
        std::cout << "1. Build the contact list with existing contacts\n";
        std::cout << "2. Add a contact to the contact list\n";
        std::cout << "3. Print the list\n";
        std::cout << "4. Search the list by name\n";
        std::cout << "5. Sort the list by age\n";
        std::cout << "6. Delete the list\n";
        std::cout << "7. Build the binary tree with existing contacts\n";
        std::cout << "8. Add a contact to a binary tree\n";
        std::cout << "9. Print the tree\n";
        std::cout << "10. Buil hash table with existing contacts\n";
        std::cout << "11. Add a contact to hash table\n";
        std::cout << "12. Search hash table for a contact\n";
        std::cout << "13. Quit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch(choice) {
            case 1:
                list = new Contact_list; // 初始化 list
                list->add_front(node2);
                list->add_front(node1);
                list->add_end(node3);
                list->add_end(node4);
                list->add_end(node5);
                list->add_end(node6);
                break;
            case 2:
                std::cout << "Enter contact name: ";
                std::cin >> name;
                std::cout << "Enter contact gender: ";
                std::cin >> gender;
                std::cout << "Enter contact age: ";
                std::cin >> age;
                new_contact = Contact(name, gender, age);
                new_node = new Node(new_contact);
                list->add_end(new_node);
                break;
            case 3:
                if(list == nullptr) {
                    std::cout << "No list.\n"; 
                } else {
                    list->print_list();
                }
                break;
            case 4:
                if(list == nullptr) {
                    std::cout << "No list.\n"; 
                } else {
                    list->search_by_name(name);
                }
                break;
            case 5:
                if(list == nullptr) {
                    std::cout << "No list.\n"; 
                } else {
                    list->sort_by_age();
                }
                break;
            case 6:
                if(list == nullptr) {
                    std::cout << "No list.\n"; 
                } else {
                    list->delete_list(list->head);
                }
                
                break;
            case 7:
                tree = new Tree;
                tree->insert(tree->root, contact2);
                tree->insert(tree->root, contact5);
                tree->insert(tree->root, contact3);
                tree->insert(tree->root, contact4);
                tree->insert(tree->root, contact1);
                tree->insert(tree->root, contact6);
                break;
            case 8:
                std::cout << "Enter contact name: ";
                std::cin >> name;
                std::cout << "Enter contact gender: ";
                std::cin >> gender;
                std::cout << "Enter contact age: ";
                std::cin >> age;
                new_contact = Contact(name, gender, age);
              
                    tree->insert(tree->root, new_contact);
                
                break;
            case 9:
                if(tree == nullptr) {
                    std::cout << "No tree.\n"; 
                } else {
                    tree->print_tree(tree->root);
                }
                break;
            case 10:
                contacts_hash_table.hash_insert(contact1.get_name(), contact1);
                contacts_hash_table.hash_insert(contact2.get_name(), contact2);
                contacts_hash_table.hash_insert(contact3.get_name(), contact3);
                contacts_hash_table.hash_insert(contact4.get_name(), contact4);
                contacts_hash_table.hash_insert(contact5.get_name(), contact5);
                contacts_hash_table.hash_insert(contact6.get_name(), contact6);
                break;
            case 11:
                std::cout << "Enter contact name: ";
                std::cin >> name;
                std::cout << "Enter contact gender: ";
                std::cin >> gender;
                std::cout << "Enter contact age: ";
                std::cin >> age;
                new_contact = Contact(name, gender, age);
                contacts_hash_table.hash_insert(name, new_contact);
                break;
            case 12:
                contacts_hash_table.hash_search(name);

                break;
            case 13:
                std::cout << "Exiting the program." << std::endl;

                if(list != nullptr) {
                    if(tree == nullptr) {
                        list->delete_list(list->head);
                        delete list;
                    }
                    
                }
                if(tree != nullptr) {
                    tree->deleteTree(tree->root);
                    delete tree;
                }
                if(list == nullptr && tree == nullptr){
                    delete node1;
                    delete node2;
                    delete node3;
                    delete node4;
                    delete node5;
                    delete node6;
                }
                break;
            default:
                std::cout << "Invalid choice. Try again." << std::endl;
        }
     } while (choice != 13);
    

    return 0;
}