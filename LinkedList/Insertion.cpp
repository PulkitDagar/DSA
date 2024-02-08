#include <iostream>
using namespace std;

class Node {
  public:
  int data;
  Node* next;

  Node(){    ///default constructor
    this->data = 0;
    this->next = NULL;
  };

  Node(int data){   ///parameterized constructor
    this->data = data;
    this->next = NULL;
  };

};

///insertion of an element
void insertATHead(Node* &head, int data){
  //step 1: create a new node
  Node* newNode = new Node(data);

  ///step2: attach krdo newnode k pointer ko head k sth
  newNode->next = head;

  //step 3:: head ko starting me lga do
  head = newNode;
};


/// function to print an array
void print(Node* &head){

    Node* temp = head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
}

int main() {

  Node* head = new Node(10);
  insertATHead(head,20);
  insertATHead(head,60);
  insertATHead(head,80);
  insertATHead(head,90);
  

  print(head);
  
  return 0;
}