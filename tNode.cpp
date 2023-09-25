#include <iostream>
#include <string>
#include <vector>
#include "at1.h"

//TNode class
//constructor
TNode::TNode(Contact person) : left(nullptr), right(nullptr), contact(person) {
    left = nullptr;
    right = nullptr;
}

//method
void TNode::print_tNode() {
    this->contact.print_contact();
};


