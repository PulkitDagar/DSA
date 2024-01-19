//we know + sign is used to concate two things but we give it functionality of what - sign do
#include<iostream>
using namespace std;

class Param{
    public:
    int val;
    void operator+(Param&object2){
        int val1 = this->val;
        int val2 = object2.val;

        cout<<(val2-val1)<<endl;
    }

};
int main(){

    Param object1,object2;

    object1.val = 7;
    object2.val = 2;

    object1+object2;

    return 0;
}