//Multiple Inheritance means when we have multiple parents and a single child and child inherit from both
// of them
#include<iostream>
using namespace std;

class A{
    public:
    int physics;
};

class B {
    public:
    int chemistry;
};

class C: public A, public B{
    public:
    int maths;
};

int main(){

    C obj;
    cout<<obj.physics<<" "<<obj.chemistry<<" "<<obj.maths<<endl;
    return 0;
}