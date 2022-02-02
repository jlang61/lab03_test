// intlist.cpp
// Implements class IntList
// YOUR NAME(S), AND DATE

#include "intlist.h"

#include <iostream>
using std::cout;

// copy constructor
IntList::IntList(const IntList& source) {
  
  Node* temp = new Node;
  temp = source.first; 
  while (temp){
    this->append(temp->info);
    temp = temp->next;
  }
}

// destructor deletes all nodes
IntList::~IntList() {
  Node* temp = this->first;
  Node* delnode;
  while(temp){
    delnode = temp;
    temp = temp->next;
    delete delnode;
  }
}


// return sum of values in list
int IntList::sum() const {
  Node* temp = new Node;
  temp = this->first;
  int sum = 0;
  while(temp){
    sum += temp->info;
    temp = temp->next;
  }
  cout << "sum = " << sum << std::endl;
  return sum; // REPLACE THIS NON-SOLUTION
}

// returns true if value is in the list; false if not
bool IntList::contains(int value) const {
  Node* temp = new Node;
  temp = this->first;
  while(temp){
    if (temp->info == value){
      return true;
    }
    temp = temp->next;
  }
    return false; // REPLACE THIS NON-SOLUTION
}

// returns maximum value in list, or 0 if empty list
int IntList::max() const {
  Node* temp = new Node;
  temp = this->first;
  if(temp != nullptr){
    int max = temp->info;
    while(temp){
      if (temp->info > max){
        max = temp->info;
      }
      temp = temp->next;
    }
    return max;
  }
  else{
      return 0;
  } // REPLACE THIS NON-SOLUTION
}

// returns average (arithmetic mean) of all values, or
// 0 if list is empty
double IntList::average() const {
  if (this->first == nullptr){
    return 0.0;
  }
  Node* temp = this->first;
  double sum = 0;
  double count = 0.0;
  while(temp){
    sum += temp->info;
    count ++;
    temp = temp -> next;
  }
  double average = sum / count;
  
    return average; // REPLACE THIS NON-SOLUTION
}

// inserts value as new node at beginning of list
void IntList::insertFirst(int value) {
  Node* temp = new Node;
  temp->info = value;
  temp->next = this->first;
  this->first = temp;
}

//Assignment operator should copy the list from the source
//to this list, deleting/replacing any existing nodes
IntList& IntList::operator=(const IntList& source){
  Node* temp = new Node;
  Node* delnode;
  if (this->first != nullptr){
    temp = this->first;
    delnode = temp;
    while(temp){
      temp = temp->next;
      delete delnode;
      delnode = temp;
    }
  }
  temp = source.first;
  this->first = nullptr;
  while(temp){
    this->append(temp->info);
    temp = temp->next;
  }
  temp = this->first;
  return *this;
}



// DO NOT CHANGE ANYTHING BELOW (READ IT THOUGH)

// constructor sets up empty list
IntList::IntList() : first(0) { }


// append value at end of list
void IntList::append(int value) {
    if (first == 0) { // empty list
        first = new Node;
        first->info = value;
        first->next = 0;
    }
    else {
        Node *n = first;
        while (n->next) // not last node yet
            n = n->next;
        n->next = new Node;
        n->next->info = value;
        n->next->next = 0;
    }
}

// print values enclose in [], separated by spaces
void IntList::print() const {
    Node *n = first;
    cout << '[';
    while (n) {
        cout << n->info;
        if (n->next)
            cout << " ";
        n = n->next;
    }
    cout << ']';
}

// return count of values
int IntList::count() const {
    int result = 0;
    Node *n = first;
    while (n) {
        ++result;
        n = n->next;
    }
    return result;
}
