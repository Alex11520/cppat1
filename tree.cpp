#include <iostream>
#include <string>
#include <vector>
#include <cctype> //for toupper(to upper case)
#include "at1.h"

//Tree class
//constructor
Tree::Tree(){
    root = nullptr;
}

//method
// void Tree::insert(Contact person) {
//     TNode* node = new TNode(person);
//     if (root == nullptr) {
//         root = node;
//         return;
//     }
//     TNode* curr = root;
//     while(curr != nullptr){
//         if (node->contact.get_age() < curr->contact.get_age()) {
//             if(curr->left == nullptr) {
//                 curr->left = node;
//                 return;
//             }
//             curr = curr->left;
//         }
//         if (node->contact.get_age() > curr->contact.get_age()) {
//             if(curr->right == nullptr) {
//                 curr->right = node;
//                 return;
//             }
//             curr = curr->right;            
//         }
//         return;
//     }
// }
void Tree::insert(TNode*& node, Contact person) {
    if (node == nullptr) {
        node = new TNode(person);
        return;
    }

    if (person.get_age() < node->contact.get_age()) {
        insert(node->left, person);
    } else if (person.get_age() > node->contact.get_age()) {
        insert(node->right, person);
    }
}


void Tree::print_tree(TNode* node) {
    if (node == nullptr)
        return;

    print_tree(node->left);
    node->contact.print_contact();
    print_tree(node->right);
}



void Tree::deleteTree(TNode* node) {
    if (node == nullptr) {
        return;
    }

    // recursion delete every node
    deleteTree(node->left);
    deleteTree(node->right);

    // delete current node
    delete node;

    //set root null
    root = nullptr;
}


