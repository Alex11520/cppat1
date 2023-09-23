#include <iostream>
#include <string>
#include <vector>
#include <cctype> //for toupper(to upper case)
#include "at1.h"

//TNode class
//constructor
TNode::TNode(Contact &person) : parent(nullptr), left(nullptr), right(nullptr), contact(person) {
    parent = nullptr;
    left = nullptr;
    right = nullptr;
}

//method
void TNode::link_left(TNode* node) {
    if(node == nullptr){
        return;
    } else {
        if(this->left != nullptr){
            this->left->parent = node;
            node->left = this->left;
            node->parent = this;
            this->left = node;
        }
        if(this->left == nullptr){
            this->left = node;
            node->parent = this;
        }
    }
}

void TNode::link_right(TNode* node) {
    if(node == nullptr){
        return;
    } else {
        if(this->right != nullptr){
            this->right->parent = node;
            node->right = this->right;
            node->parent = this;
            this->right = node;
        }
        if(this->right == nullptr){
            this->right = node;
            node->parent = this;
        }
    }
}

void TNode::link_parent_right(TNode* node){
    if(node == nullptr){
        return;
    } else if(this == nullptr){
        std::cout << "current node is null" << std::endl;
        return;
    } else {
        if(this->parent == nullptr) {
            node->left = this;
            this->parent = node;
        } else {
            if(this->parent->left == this) {
                this->parent->left = node;
                node->parent = this->parent;
                node->left = this;
                this->parent = node;
            } else if(this->parent->right == this) {
                char answer;
                do {
                    std::cout << "current node can only be left side of new node. would you like to do that? Y/N: " << std::endl;
                    std::cin >> answer;
                    answer = toupper(answer);
                    if(answer == 'Y') {
                        this->parent->right = node;
                        node->parent = this->parent;
                        node->right = this;
                        this->parent = node;
                    } else if (answer == 'N') {
                        return;
                    }
                } while (answer != 'Y' || answer != 'N');
            }
        }
    }
}

void TNode::link_parent_left(TNode* node) {
    if(node == nullptr){
        return;
    } else if(this == nullptr){
        std::cout << "current node is null" << std::endl;
        return;
    } else {
        if(this->parent == nullptr) {
            node->right = this;
            this->parent = node;
        } else {
            if(this->parent->right == this) {
                this->parent->right = node;
                node->parent = this->parent;
                node->right = this;
                this->parent = node;
            } else if(this->parent->left == this) {
                char answer;
                do {
                    std::cout << "current node can only be right side of new node. would you like to do that? Y/N: " << std::endl;
                    
                    std::cin >> answer;
                    answer = toupper(answer);
                    if(answer == 'Y') {
                        this->parent->left = node;
                        node->parent = this->parent;
                        node->left = this;
                        this->parent = node;
                        return;                       
                    } else if (answer == 'N') {
                        return;
                    }
                    
                } while (answer != 'Y' && answer != 'N');
            }
        }
    }
        
    
}

void TNode::print_tNode() {
    this->contact.print_contact();
};
