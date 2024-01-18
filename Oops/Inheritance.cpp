#include<iostream>
using namespace std;

//parent class
class Animal {

    public:
    int age;
    int weight;

    void eat(){
        cout<<"Eating"<<endl;
    }

    void sleep(){
        cout<<"Sleeping"<<endl;
    }
};

//child class

class Dog: public Animal{

};

int main(){

    //create a object of child class and when running we see it already inherits the property of its parent class
    Dog d1;
    d1.eat();

    return 0;
}