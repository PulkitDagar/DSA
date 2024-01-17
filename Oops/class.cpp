//Class is basically a blueprint of an object or we can say that a class is a user-defined data type
// that has data members and member functions

#include<iostream>
using namespace std;


//syntax to create a class
class Animal {

    private:
    int weight;
    public:
    //state or properties
    int age;
    string name;

    //function or behaviour
    void eat(){

    };

    void sleep(){
        
    };

    int getWeight(){
        return weight;
    }

    void setWeight(int w){
        weight = w;
    }


};

int main(){
    // cout<<"the size of an empty class is"<<sizeof(Animal);
    //the size of an empty class is 1;

    //object creation

    //static memory allocation


    // Animal ramesh;
    // ramesh.age = 12;
    //cout<<"The age of ramesh is "<<ramesh.age<<endl; //it gives an error bcoz age is a private access modifier
    // cout<<"The age of ramesh is"<<ramesh.age<<endl; //it works bcoz we marked public in class



    //if we want to access a private member of a class so for that we use getter and setter function

    //set the weight
    // ramesh.setWeight(101);
    // cout<<"the weight of ramesh is"<<ramesh.getWeight()<<endl;

    
  //   -----------------------------------------------------------------------------------------------------------
    //DYNAMIC MEMORY ALLOCATION
    
    Animal* Suresh = new Animal;
    Suresh->age = 15;
    cout<<"the age of suresh of is"<<Suresh->age<<endl;

};