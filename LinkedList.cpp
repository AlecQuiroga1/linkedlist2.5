// LinkedList.cpp : This file contains the 'main' function. Program execution begins and ends there.
// Alec Quiroga
// Intro to Computational Theory.
// 1/21/2021

#include <iostream>

using namespace std;

//Creates the class node used for a standard linked list.
class Node {
public:
    string data;
    Node* next;
};

//Creates a node useable for a doubly linked list.
class DoublyNode {
public:
    string data;
    DoublyNode* next;
    DoublyNode* previous;
};


/*
This class contains the methods used for computation 
of the doubly linked list. 
*/
class DoublyList {
public:
    DoublyNode* head;
    DoublyNode* tail;

public: 

    DoublyList() {
        
        head = NULL;
        tail = NULL;

    }

    // This method adds a string character to a doubly linked list.
    void addDoublyNode(string n) {

        DoublyNode* tempNode = new DoublyNode;
        tempNode->data = n;
        tempNode->next = NULL;
        tempNode->previous = NULL;

        // If the first node is null then it will initialize it.
        if (head == NULL) { 
            
            head = tempNode;
            tail = tempNode;

         // If there is only one letter it sets the previous node to be head.
        } else if (countSize() == 1){

            tail->next = tempNode;
            tail->previous = head;
            
            // Lets the tail to equal the last node in the list.
            tail = tail->next;

        }
        else {
            
            // Sets every node after the first two.
            tail->next = tempNode;
            tail->previous = tail;
            tail = tail->next;
        }

    }

    /*
    This method counts the size of a linked list by looping through
    the list and counting at the 
    */
    int countSize() {
        DoublyNode* node;
        node = tail;
        int count = 0;
        
        while (node != NULL) {
            count++;
            node = node->previous;
        }

        return count;
    }


    // Loop through and print the linked list
    void printList() {

        // Initializes the pointer node and sets it to tail 
        DoublyNode* node;
        node = tail;

        // Loops through the linked list from the tail to the head.
        while (node != NULL) {

            cout << node->data;
            node = node->previous;

        }
    }
};

/*
This class is used for a singly linked list.
It is filled with the bottom half of the word from the 
doubly linked list. Then used to compare to the top half 
of the letters in the doubly linked list.
*/

class LinkedList {
public:

    Node* head;
    Node* tail;

public:

    LinkedList() {

        head = NULL;
        tail = NULL;
    }

    // This method adds a new node to the list as a string.
    void addListNode(string n) {


        Node* tempNode = new Node;
        tempNode->data = n;
        tempNode->next = NULL;

        // If the first node is null then it sets it to temp.
        if (head == NULL) {

            //initializes the head and tail to the current tempNode.
            head = tempNode;
            tail = tempNode;
        }
        else {
            tail->next = tempNode; 
            tail = tail->next; 
        }
    }
};



int main() {
    
    int listSize;
    DoublyList doublyList;
    LinkedList secondHalf;

    // Adds the string letters to the linked list.
    doublyList.addDoublyNode("s");
    doublyList.addDoublyNode("o");
    doublyList.addDoublyNode("l");
    doublyList.addDoublyNode("o");
    doublyList.addDoublyNode("s");

    listSize = doublyList.countSize();
    cout << listSize << endl;
    doublyList.printList();

    return 0;
}



