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

int main(){
    
    Node* head = new Node();


    return 0;
}