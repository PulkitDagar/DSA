#include <iostream>
#include <stack>
using namespace std;

int main()
{

  // creation
  stack<int> st;

  // insertion of element
  st.push(10);
  st.push(20);
  st.push(30);
  st.push(40);

  // remove
  st.pop();

  // check element on top
  cout << "Element on top is" << st.top() << endl;

  // size
  cout << "The size of stack is" << st.size() << endl;

  // check empty
  if (st.empty())
  {
    cout << "stack is empty" << endl;
  }
  else
  {
    cout << "stack is not empty" << endl;
  }

  // how to print stack
  while (!st.empty())
  {
    cout << st.top() << " ";
    st.pop();
  }
  cout << endl;
  return 0;
}