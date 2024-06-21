///sort 0s 1s and 2s in an linked list
/// first approach with data replacement

///remove duplicates from the sorted linked list
#include <iostream>
using namespace std;
class Node{
  public:
  int data;
  Node* next;

  Node(int data){
    this->data = data;
    this->next = NULL;
  };
};

void sortZeroOneTwo(Node* &head){
  ///step1: find count of zeroes one and two
  int zero = 0;
  int one = 0;
  int two = 0;

  Node* temp = head;
  while(temp!=NULL){
    if(temp->data == 0){
      zero++;
    }
    else if(temp->data ==1){
      one++;
    }
    else{
      two++;
    }
    temp = temp->next;
  }

  ///step2:place 0 1 2 in their original place
  temp = head;
  
  //fill zeroes
    while(zero--){
      temp->data = 0;
      temp = temp->next;
    }
    while(one--){
      temp->data = 1;
      temp = temp->next;
    }
    while(two--){
      temp->data = 2;
      temp = temp->next;
    }
  
}

void print(Node* &head){
  Node* temp = head;
  while(temp!=NULL){
    cout<<temp->data<<" ";
    temp = temp->next;
  }
  cout<<endl;
};


int main() {
  Node* head = new Node(1);
  Node* second = new Node(2);
  Node* third = new Node(2);
  Node* fourth = new Node(1);
  Node* fifth = new Node(2);
  Node* sixth = new Node(0);

  head->next = second;
  second->next = third;
  third->next = fourth;
  fourth->next = fifth;
  fifth->next = sixth;

  cout<<"Input Linked List"<<" ";
  print(head);

  cout<<endl;

  sortZeroOneTwo(head);
  print(head);



 
  return 0;
}