// find the middle node of the linked list
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

Node* getMiddle(Node* &head){
  //ll is empty
  if(head==NULL){
    cout<<"Linked list is empty"<<endl;
    return head;
  }

  ///if there is only one element in linked list
  if(head->next == NULL){
    return head;
  }

  //Odd-length list: The slow pointer points to the exact middle node.
  // Even-length list: The slow pointer points to the second middle node.
  ////example no 2 to keep in mind

  // ListNode* findMiddle(ListNode* head) {
  //   ListNode* slow = head;
  //   ListNode* fast = head;

  //   // Move until fast reaches the end
  //   while (fast != nullptr && fast->next != nullptr) {
  //       slow = slow->next;       // Move slow by 1 step
  //       fast = fast->next->next; // Move fast by 2 steps
  //   }

  //   // Slow is now pointing to the middle node
  //   return slow;
  // }




























  Node* slow = head;
  Node* fast = head;   //Node* fast = head->next in case you need exact middle one in even case
  //linked have more than 1 element
  while(slow!=NULL && fast!=NULL){
    fast = fast->next;
    if(fast!=NULL){
      fast = fast->next;
      slow = slow->next;
    }
  }
  return slow;

}

void print(Node* &head){
  Node* temp = head;
  while(temp!=NULL){
    cout<<temp->data<<" ";
    temp = temp->next;

  }
  cout<<endl;
}



int main() {
  Node* head= new Node(20);
  Node* second = new Node(30);
  Node* third = new Node(40);
  Node* fourth = new Node(50);
  Node* fifth = new Node(60);

  head->next = second;
  second->next = third;
  third->next = fourth;
  fourth->next = fifth;
  fifth->next = NULL;

  print(head);

  cout<<"Middle node is"<<getMiddle(head)->data<<endl;



  
  return 0;
}