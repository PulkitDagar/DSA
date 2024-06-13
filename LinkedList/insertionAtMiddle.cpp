#include <iostream>
using namespace std;

class Node{

  public:
  int data;
  Node* next;

  Node(){             //default constructor
    this->data = 0;
    this->next = NULL;
  };

  Node(int data){
    this->data = data;
    this->next = NULL;
  };

  //destructor for deletion
  ~Node(){
    cout<<"Destructor called for: "<<this->data<<" ";
  }

};


void insertionAtHead(Node* &head, Node* &tail, int data){
  if(head==NULL){
    //ek node banao
    Node* newNode = new Node(data);
    head = newNode;
    tail = newNode;
    return;
  }


  ///crete a new node
  Node* newNode = new Node(data);


  ///new node k next ko head k equal krdo
  newNode->next = head;

  ///head ko aage le aao
  head = newNode;
};


///insertion at tail
void insertionAtTail(Node* &head, Node* &tail, int data){
  //ager null h toh kya karna hai
  if(head == NULL){
    //create a new node
    Node* newNode = new Node(data);
    head = newNode;
    tail = newNode;
    return;
  }


  ///create a new node
  Node* newNode = new Node(data);

  ///current node k next ko new node k braber krdo
  tail->next = newNode;


  ///tail ko new Node k braber krdo
  tail = newNode;



};

int findLength(Node* &head){
  int len = 0;
  Node*temp = head;

  while(temp!=NULL){
    temp = temp->next;
    len++;
  }
  return len;
}


void insertionAtPosition(Node* &head, Node* &tail, int data, int position){
  ///step 1: check kro linked list empty toh nhi
  if(head==NULL){
    Node* newNode = new Node(data);

    head = newNode;
    tail = newNode;
    return;
  }


  //step 2: Position find out kro find prev and current position
  if(position==0){
    insertionAtHead(head,tail,data);
    return;
  };

  int len = findLength(head);
  if(position>=len){
    insertionAtTail(head,tail,data);
    return;
  };

  // find prev and curr position;
  int i =1;
  Node* prev = head;

  while(i<position){
    prev = prev->next;
    i++;
  }
  Node* curr = prev->next;




  //step 3: create a new Node
  Node* newNode = new Node(data);

  //step 4: newNode k next ko current k braber krdo
  newNode->next = curr;


  ///step 5: prev node ka next h usne newNode k braber krdo
  prev->next = newNode;

}

void deleteNode(Node* &head, Node* &tail, int position){
  //empty linked list
  if(head==NULL){
    cout<<"Cannot delete bcoz linked list is empty"<<endl;
  };

  int len = findLength(head);
  //delete from head
  if(position == 1){
    //first node ko delete krdo
    Node* temp = head;
    head = temp->next;
    temp->next = NULL;
    delete temp;   //whenever we free the dynamically allocated memory the destructor get called

  }

  else if(position==len){
    ///last node ko delete krdo
    Node* prev = head;
    while(prev-> next !=tail){
      prev = prev->next;
    }

    //prev node ka link null kro
    prev->next = NULL;

    //node delete kro
    delete tail;

    //tail ko update kro
    tail = prev;
  }
  else{
    //middle se delete krdo

    //set prev and current pointers
    int i = 1;
    Node* prev = head;
    while(i<position-1){
      prev = prev->next;
      i++;
    }
    Node* curr = prev->next;

    //step2: prev k next ko curr k next k braber krdo
    prev->next = curr->next;
    //step3:
    curr->next = NULL;

    //4:
    delete curr;
  }
}




void print(Node* &head){
  Node* temp = head;

  while(temp!=NULL){
    cout<<temp->data<<" ";
    temp = temp->next;
  }
}

int main() {

  Node* head = NULL;
  Node* tail = NULL;

  insertionAtHead(head,tail,20);
  insertionAtHead(head,tail,30);
  insertionAtHead(head,tail,40);

  insertionAtTail(head,tail,60);

  insertionAtPosition(head,tail,101,5);

  print(head);
  
  return 0;
}