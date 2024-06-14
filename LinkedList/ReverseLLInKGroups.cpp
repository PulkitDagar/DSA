#include <iostream>
using namespace std;

class Node{
  public:
  int data;
  Node* next;

  Node(int data){
    this->data = data;
    this->next = NULL;
  }
};

int getLength(Node* &head){
  int len = 0;
  Node* temp = head;
  while(temp!=NULL){
    temp = temp->next;
    len++;
  }
  return len;
}

Node* reverseKNodes(Node* &head, int k){
  if(head==NULL){
    cout<<" linked list is empty"<<endl;
    return NULL;
  }
  // if(head->next == NULL){
  //   return head; //means only a single element is present
  // }

  int len = getLength(head);
  if(k>len){
    cout<<"Enter valid value of k"<<endl;
    return head;
  };
  ///it means the no of elements in linked list is greater than k
  //step1: reverse first k nodes 
  Node* prev = NULL;
  Node* curr = head;
  Node* forward = head->next;
  int count = 0;

  while(count<k){
    forward = curr->next;
    curr->next = prev;
    prev = curr;
    curr = forward;
    count++;
  }

  if(forward!=NULL){
    //we still have nodes left to reverse
    head->next = reverseKNodes(forward,k);
  }

  //3; RETURN HEAD OF MODIFIED NODE
  return prev;
}

void print(Node* &head){
  Node* temp = head;
  while(temp!=NULL){
    cout<<temp->data<<" ";
    temp= temp->next;
  }
  cout<<endl;
}



int main() {
  Node* head= new Node(20);
  Node* second = new Node(30);
  Node* third = new Node(40);
  Node* fourth = new Node(50);
  Node* fifth = new Node(60);
  Node* sixth = new Node(70);

  head->next = second;
  second->next = third;
  third->next = fourth;
  fourth->next = fifth;
  fifth->next = sixth;

  print(head);
  cout<<endl;
  head = reverseKNodes(head,3);
  print(head);





  
  return 0;
}