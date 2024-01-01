#include <iostream>
using namespace std;

void printCounting(int n) {
    //base case
    if(n==0){
        return;
    }

    ///processing
    cout<<n<<endl;

    ///recurssive call
    printCounting(n-1);
}

int main() {
    int n = 5;
    cout<<"The given order of counting are" <<endl;

    printCounting(n);


    return 0;
}