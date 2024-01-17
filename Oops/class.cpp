//Class is basically a blueprint of an object or we can say that a class is a user-defined data type
// that has data members and member functions

#include<iostream>
using namespace std;


//syntax to create a class
class Animal {

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
    cout<<"the size of an empty class is"<<sizeof(Animal);
    //the size of an empty class is 1;

}