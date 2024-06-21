//ager left or right se dono se pdhne per same he answer aata hai to mai kheta hu ki palindrome hai
//approach1:: let say we have a linked list 1,2,3,4,5,6 so we make a new linked list by reversing it
//and then compare it with the original one.. the space and time complexities of this is O(n);


////approach 2: find middle then revrse linked list after middle node and then compare both halves 
//better than previous appraoch bcoz here the space complexities is o(1);
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


Node* reverse(Node* &head){
  Node* prev = NULL;
  Node* curr = head;
  Node* forward = curr->next;

  while(curr!=NULL){
    forward = curr->next;
    curr->next = prev;
    prev = curr;
    curr = forward;
  }

  return prev;
}

//write the function
bool checkPalindrome(Node* &head){
  //check if linked list is empty or not
  if(head==NULL){
    cout<<"linked list is empty";
    return true;
  }

  //check if there is only one element present
  if(head->next == NULL){
    cout<<"linked list is palindrome"<<endl;
    return true;
  }

  //now we check for more than one element
  //in step1 we find the middle
  Node* slow = head;
  Node* fast = head->next;

  while(slow!=NULL && fast!=NULL){
    fast = fast->next;
    if(fast!=NULL){
      fast = fast->next;
      slow = slow->next;
    }
  }

  ///slow is pointing to middle node
  //in step2 we reverse the linked list
  Node* reverseLLKaHead = reverse(slow->next);

  slow->next = reverseLLKaHead;

  ///in step3 we compare both the parts
  Node* temp1 = head;
  Node* temp2 = reverseLLKaHead;

  while(temp2!=NULL){
    if(temp1->data !=temp2->data){
      //not an palindrome
      return false;
    }
    else{
      ///if the data is same then aage bdho
      temp1 = temp1->next;
      temp2 = temp2->next;
    }
  }
  return true;
}


int main() {
  Node* head = new Node(10);
  Node* second = new Node(20);
  Node* third = new Node(30);
  Node* fourth = new Node(20);
  Node* fifth = new Node(100);

  head->next = second;
  second->next = third;
  third->next = fourth;
  fourth->next = fifth;

  bool isPalindrome = checkPalindrome(head);

  if(isPalindrome){
    cout<<"Linked list is a valid Palindrome"<<endl;
  } else{
    cout<<"Linked list is not Palindrome"<<endl;
  }
  return 0;
}