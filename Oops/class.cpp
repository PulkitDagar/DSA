//Class is basically a blueprint of an object or we can say that a class is a user-defined data type
// that has data members and member functions

#include<iostream>
using namespace std;


//syntax to create a class
class Animal {

    public:
    //state or properties
    int age;
    string name;

    //function or behaviour
    void eat(){

    };

    void sleep(){
        
    };


};

int main(){
    // cout<<"the size of an empty class is"<<sizeof(Animal);
    //the size of an empty class is 1;

    //object creation

    //static memory allocation


    Animal ramesh;
    //cout<<"The age of ramesh is "<<ramesh.age<<endl; //it gives an error bcoz age is a private access modifier
    cout<<"The age of ramesh is"<<ramesh.age<<endl; //it works bcoz we marked public in class
}