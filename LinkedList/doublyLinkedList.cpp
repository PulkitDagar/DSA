#include <iostream>
using namespace std;

class Node{

  public:
  int data;
  Node* prev = NULL;
  Node* next = NULL;

  //default constructor
  Node(){
    this->data = 0;
    this->prev = NULL;
    this->next = NULL;
  };

  //parameterized constructor
  Node(int data){
    this->data = data;
    this->prev = NULL;
    this->next = NULL;
  };
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


void insertionAtHead(Node* &head, Node* &tail, int data){
  //step1: check linked list is empty or not
  if(head==NULL){
    Node* newNode = new Node(data);
    head = newNode;
    tail = newNode;

    return;
  };

  // step2: create a new node 
  Node* newNode = new Node(data);

  //step 3: newNode k next ko head k braber krdo
  newNode->next = head;

  ///step 4: head k prev ko bhi new node k braber krdo
  head->prev = newNode;

  // step 5:  head ko new node k braber krdo
  head = newNode;
};

void insertionAtTail(Node* &head, Node* &tail, int data){
   //step1: check linked list is empty or not
  if(head==NULL){
    Node* newNode = new Node(data);
    head = newNode;
    tail = newNode;

    return;
  };
  //LL is not empty
  Node* newNode = new Node(data);
  tail->next = newNode;
  newNode->prev = tail;
  tail = newNode;
}

void insertAtPosition(Node* &head, Node* &tail, int data, int position){
    //step1: check linked list is empty or not
  if(head==NULL){
    Node* newNode = new Node(data);
    head = newNode;
    tail = newNode;

    return;
  };
  //LL is not empty
  if(position==1){
    insertionAtHead(head,tail,data);
    return;
  }

  int len = getLength(head);
  if(position>=len){
    insertionAtTail(head,tail,data);
    return;
  }

  
  // find prev and curr position;
  int i =1;
  Node* prevNode = head;

  while(i<position-1){
    prevNode = prevNode->next;
    i++;
  }
  Node* curr = prevNode->next;

  //create a new Node
  Node* newNode = new Node(data);

  prevNode->next = newNode;
  newNode->prev = prevNode;
  curr->prev = newNode;
  newNode->next = curr;

  
}


void print(Node* &head){
  Node* temp = head;
  while(temp!= NULL){
    cout<<temp->data <<" ";
    temp = temp->next;
  }
}



int main() {

  Node* first = new Node(10);
  Node* second = new Node(20);
  Node* third = new Node(30);

  Node* head = first;
  Node* tail = third;

  first->next = second;
  second->prev = first;

  second->next = third;
  third->prev = second;

  print(first);
  cout<<endl;

   insertionAtHead(head,tail,101);
   print(head);

   cout<<endl;

   insertionAtTail(head,tail,103);
   print(head);

    cout<<endl;

   insertAtPosition(head,tail,500,4);
   print(head);

  
  return 0;
}