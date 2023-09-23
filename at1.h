#ifndef AT1_H
#define AT1_H

#include <iostream>
#include <string>
#include <vector>


class Contact {
protected:
    //attribute
    std::string name;
    char gender;
    int age;

public:
    //get set
    std::string get_name() const;
    void set_name(std::string person_name);

    char get_gender() const;
    void set_gender(char person_gender);

    int get_age() const;
    void set_age(int person_age);

    //constructor
    Contact(std::string person_name, char person_gender, int person_age);
    void print_contact();
};



class Node {
public:
    //attribute
    Node* prev;
    Node* next;
    Contact contact;

    //constructor
    Node(Contact &person);

    //link to other nodes
    void link_prev(Node* prevNode);
    void link_next(Node* nextNode);
    void print_node();
};



class Contact_list {
public:
    //attribute
    Node* head;
    Node* tail;

    //constructor
    Contact_list();

    //link to nodes
    void add_end(Node* node);
    void add_front(Node* node);
    void print_list();
    std::string get_search_name();
    void search_by_name();
};


class TNode {
public:
    //attribute
    TNode* parent;
    TNode* left;
    TNode* right;
    Contact contact;

    //constructor
    TNode(Contact &person);

    //method
    void link_left(TNode* node);
    void link_right(TNode* node);
    void link_parent_left(TNode* node);
    void link_parent_right(TNode* node);
    
    void print_tNode();
};


class Tree {
public:
    //attribute
    TNode* root;

    //constructor
    Tree();

    //method
    void print_tree();
};

#endif