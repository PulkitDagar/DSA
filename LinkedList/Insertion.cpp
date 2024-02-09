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

///insertion of an element at the head(starting)
void insertATHead(Node* &head, Node* &tail, int data){

  //step 1: create a new node
  Node* newNode = new Node(data);

  ///step2: attach krdo newnode k pointer ko head k sth
  newNode->next = head;

  //step 3:: head ko starting me lga do
  ///first node
  if(head == NULL){
    tail = newNode;
  }
  head = newNode;
};


///insertion of an element at the tail(end)
void insertAtTail(Node* &head, Node* &tail, int data){

  ///step1: create a node
  Node* newNode = new Node(data);

  //step 2: connect with new node
  if(tail == NULL){
    tail = newNode;
    head = newNode;
  }
  else{
  tail->next = newNode;

  }

  ///step 3: tail ko ending me lga do
 
  tail = newNode;
};


/// function to print an link list
void print(Node* &head){

    Node* temp = head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
}

int main() {

  // Node* head = new Node(10);
  Node* head = NULL;
  Node* tail = NULL;

  // insertATHead(head,tail,20);
  // insertATHead(head,tail,60);
  // insertATHead(head,tail,80);
  // insertATHead(head,tail,90);

  insertAtTail(head,tail,5);
  insertAtTail(head,tail,40);
  

  print(head);

  
  return 0;
}








// #include <iostream>
// using namespace std;

// class Node {
//   public:
//   int data;
//   Node* next;

//   Node(){    ///default constructor
//     this->data = 0;
//     this->next = NULL;
//   };

//   Node(int data){   ///parameterized constructor
//     this->data = data;
//     this->next = NULL;
//   };

// };

// ///insertion of an element
// void insertATHead(Node* &head, int data){
//   //step 1: create a new node
//   Node* newNode = new Node(data);

//   ///step2: attach krdo newnode k pointer ko head k sth
//   newNode->next = head;

//   //step 3:: head ko starting me lga do
//   head = newNode;
// };


// /// function to print an array
// void print(Node* &head){

//     Node* temp = head;
//     while(temp!=NULL){
//         cout<<temp->data<<" ";
//         temp = temp->next;
//     }
// }

// int main() {

//   Node* head = new Node(10);
//   insertATHead(head,20);
//   insertATHead(head,60);
//   insertATHead(head,80);
//   insertATHead(head,90);
  

//   print(head);
  
//   return 0;
// }