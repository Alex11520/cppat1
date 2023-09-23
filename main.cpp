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

    // Node* node1 = new Node(contact1);
    // Node* node2 = new Node(contact2);
    // Node* node3 = new Node(contact3);
    // Node* node4 = new Node(contact4);
    // Node* node5 = new Node(contact5);
    // Node* node6 = new Node(contact6);


    // Contact_list* list = new Contact_list;
    // list->add_front(node2);
    // list->add_front(node1);
    // list->add_end(node3);
    // list->add_end(node4);
    // list->add_end(node5);
    // list->add_end(node6);
    
   
    TNode* tNode1 = new TNode(contact1);
    TNode* tNode2 = new TNode(contact2);
    TNode* tNode3 = new TNode(contact3);
    TNode* tNode4 = new TNode(contact4);
    TNode* tNode5 = new TNode(contact5);
    TNode* tNode6 = new TNode(contact6);


    //list->print_list();
    //list->search_by_name();
    tNode1->link_parent_left(tNode2);
    tNode1->link_parent_right(tNode3);
    tNode1->parent->print_tNode();

    // delete node1;
    // delete node2;
    // delete node3;
    // delete node4;
    // delete node5;
    // delete node6;
    // delete list;
    delete tNode1;
    delete tNode2;
    delete tNode3;
    delete tNode4;
    delete tNode5;
    delete tNode6;

    return 0;
}