#include<iostream>
using namespace std;

//In this we have single parent and multiple child
class Car {
    public:
    int age;
    int weight;

    void speed(){
        cout<<" speeding up"<<endl;
    };
};

class Scorpio: public Car{
    public:
    string name;
};

class Fortuner: public Car{
    string color;
};

//now we make parent class

int main(){
    Scorpio S1;
    cout<<S1.age<<endl;
    S1.speed();

    S1.name = "hello";
    cout<<S1.name<<endl;

    return 0;
};