/*
 * Name: Joe Francesconi
 * Date Submitted: 2/3/2022
 * Lab Section: 005
 * Assignment Name: Lab 1 Linked List based Stacks and Queues
 */

#pragma once

#include <iostream>
#include <string>
#include "Node.h"
using namespace std;

//This class represents a linked list of node objects
//Do not modify anything in the class interface
template <class T>
class List{

 private:
  Node<T> * start; //pointer to the first node in this list
  int mySize;  //size (or length) of this list

 public:
  List();
  ~List();
  int size();
  bool empty();
  void insertStart(T);
  void insertEnd(T);
  void insertAt(T, int);
  void removeStart();
  void removeEnd();
  void removeAt(int);
  T getFirst();
  T getLast();
  T getAt(int);
  int find(T);

  //Print the name and this list's size and values to stdout
  //This function is already implemented (no need to change it)
  void print(string name){
    cout << name << ": ";
    cout << "size = " << size();
    cout << ", values = ";
    Node<T> * iterator = start;
    while(iterator != nullptr){
      cout << iterator->value << ' ';
      iterator = iterator->next;
    }
    cout << endl;
  }

}; //end of class interface (you may modify the code below)

//Implement all of the functions below
//Construct an empty list by initializig this list's instance variables
template <class T>
List<T>::List(){
    start = nullptr;
    mySize = 0;
}

//Destroy all nodes in this list to prevent memory leaks
template <class T>
List<T>::~List(){
    Node<T> * current = start, * nextNode = nullptr;
    while (current != nullptr){
        nextNode = current->next;
        delete current;
        current = nextNode;
    }
}

//Return the size of this list
template <class T>
int List<T>::size(){
    //will count size as items are added and removed from the list.
    return mySize;
}

//Return true if this list is empty
//Otherwise, return false
template <class T>
bool List<T>::empty(){
    if (start == nullptr){
        return true;
    }else{
        return false;
    }
}

//Create a new node with value, and insert that new node
//into this list at start
template <class T>
void List<T>::insertStart(T value){
    Node<T> * newNode;
    newNode = new Node<T>(value);
    
    if (empty()){
        start = newNode;
    }else{
        newNode->next = start;
        start = newNode;
    }
    
    mySize++;
}

//Create a new node with value, and insert that new node
//into this list at end
template <class T>
void List<T>::insertEnd(T value){
    Node<T> * newNode, * current;
    newNode = new Node<T>(value);
    
    if(empty()){
        start = newNode;
    }else{
        current = start;
        while (current->next != nullptr){
            current = current->next;
        }
        current->next = newNode;
    }
    
    mySize++;
    
}

//Create a new node with value <value>, and insert that new node at position j
template <class T>
void List<T>::insertAt(T value, int j){
    if (j == 0){
        insertStart(value);
    }else if (j >= mySize){
        insertEnd(value);
    }else{
        Node<T> * newNode, * current;
        newNode = new Node<T>(value);
        int count = 0;
        
        current = start;
        while (count != (j-1)){
            current = current->next;
            count++;
        }
        newNode->next = current->next;
        current->next = newNode;
        
        mySize++;
    }
}

//Remove node at start
//Make no other changes to list
template <class T>
void List<T>::removeStart(){
    Node<T> * oldStart;
    
    oldStart = start;
    start = start->next;
    delete oldStart;
    
    mySize--;
}

//Remove node at end
//Make no other changes to list
template <class T>
void List<T>::removeEnd(){
    Node<T> * current;
    
    current = start;
    while (current->next != nullptr){
        current = current->next;
    }
    delete current;
    
    mySize--;
}

//Remove node at position j
//Make no other changes to list
template <class T>
void List<T>::removeAt(int j){
    if (j == 0){
        removeStart();
    }else if (j >= mySize){
        removeEnd();
    }else{
        Node<T> * current, * removeNode;
        int count = 0;
        
        current = start;
        while (count != (j-1)){
            current = current->next;
            count++;
        }
        removeNode = current->next;
        current->next = removeNode->next;
        delete removeNode;
        
        mySize--;
    }
}

//Return the value of the first node in the Linked List,
//If no first node, return the default constructed value: T()
template <class T>
T List<T>::getFirst(){
    if (empty()){
        return T();
    }else{
        return start->value;
    }
}

//Return the value of the last node in the Linked List,
//If no first node, return the default constructed value: T()
template <class T>
T List<T>::getLast(){
    if (empty()){
        return T();
    }else{
        Node<T> * current;
    
        current = start;
        while (current->next != nullptr){
            current = current->next;
        }
        return current->value;
    }
}

//Return the value of the node at position j in the Linked List,
//If no first node, return the default constructed value: T()
template <class T>
T List<T>::getAt(int j){
    if (empty()){
        return T();
    }else{
        Node<T> * current;
        int count = 0;
        
        current = start;
        while (count != j){
            current = current->next;
            count++;
        }
        return current->value;
    }
}

//Return the position of the (first) node whose value is equal to the key
//Otherwise, return -1
template <class T>
int List<T>::find(T key){
    if (empty()){
        return -1;
    }
    
    int count = 0;
    Node<T> * current;
    current = start;
    while (current != nullptr){
        if (current->value == key){
            return count;
        }
        current = current->next;
        count++;
    }
    return -1;
}
