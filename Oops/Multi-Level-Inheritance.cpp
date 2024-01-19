#include <iostream>
using namespace std;

//to understand multi-level inheritance the best example is we have a parent and child inherit from it then
//the grand-child inherit from both of them

class Fruit{
    public:
    string name;
};

class Mango: public Fruit{
    public:
    int weight;
};

class Alphanso:public Mango{
    public:
    int sugarLevel;
};

int main(){
    Alphanso a;
    cout<<a.name<<" "<<a.weight<<" "<<a.sugarLevel<<endl;

    return 0;
}