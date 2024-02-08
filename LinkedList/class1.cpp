#include<iostream>
using namespace std;


/// creating node
class Node {
    public:

    int data;
    Node* next;

    Node() {      ///creating constructor
        this->data = 0;
        this->next = NULL;
    };

    Node(int data){ /////parameterized constructor
        this->data = data;
        this->next = NULL;
    };

};


/// function to print an array
void print(Node* &first){

    Node* temp = first;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
}

int main(){
    
    Node* first = new Node(10);
    Node* second = new Node(20);
    Node* third = new Node(30);
    Node* fourth = new Node(40);
    Node* fifth = new Node(50);


    ///now we connect nodes to each other
    first->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = fifth;


    cout<<"Printing the linked list" <<endl;

    print(first);
    


    return 0;
}