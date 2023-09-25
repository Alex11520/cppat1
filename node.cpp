#include <iostream>
#include <string>
#include <vector>
#include "at1.h"

//Node class
//constructor
Node::Node(Contact person) : contact(person){
    prev = nullptr;
    next = nullptr;
}

//method
//link to other nodes
void Node::link_prev(Node* prevNode){ 
    if (this->prev != nullptr) {
        this->prev->next = prevNode; // 更新当前节点的前一个节点的后继节点为 prevNode
    }
    this->prev = prevNode;
    prevNode->next = this;
    prevNode->prev = this->prev;
}

void Node::link_next(Node* nextNode) {
    if(this->next != nullptr){
        this->next->prev = nextNode;
    }
    this->next = nextNode;
    nextNode->prev = this;
    nextNode->next = this->next;
}

void Node::print_node() {
    contact.print_contact();
}

