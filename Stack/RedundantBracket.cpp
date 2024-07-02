#include <iostream>
#include<stack>
using namespace std;


bool checkRedundant(string &str){
  stack<char>st;

  for(int i=0; i<str.length(); i++){
    char ch = str[i];

    if(ch =='(' || ch=='+' || ch=='-' || ch=='*' || ch== '/'){
      st.push(ch);
    }
    else if(ch == ')'){

      int operatorCount = 0;
      while(!st.empty() && st.top()!= '('){
        char temp = st.top();
        if(temp == '+' || temp == '-' || temp == '*' || temp == '/'){
          operatorCount++;
        }
        st.pop();
      }
      //yha tabhi pouchege jb count krlea honge or stack k top pr opening bracket hoga
      //so remove that also
      st.pop();

      if(operatorCount == 0){
        return true;
      }
    }
  }
  //ager hmm yha tak aaye hai toh pkka ek operator mila hoga
  return false;
}

int main() {
  string str = "( ((a+b) *(c+d)))";
  bool ans = checkRedundant(str);

  if(ans==true){
    cout<<"Redundant bracket present"<<endl;
  }
  else{
    cout<<"Redundant breacket is not present"<<endl;
  }
  return 0;
}