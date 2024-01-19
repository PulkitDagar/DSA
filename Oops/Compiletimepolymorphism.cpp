#include<iostream>
using namespace std;


///we make a many form of a single function
//function overloading
class Maths{

    public:
    int sum(int a, int b){
        return a+b;
    };

    int sum(int a, int b,int c){
        return a+b+c;
    };

    int sum(int a, float b){
        return a+b;
    };
};

int main(){

    Maths obj;
    cout<<obj.sum(7,8);
    return 0;
}