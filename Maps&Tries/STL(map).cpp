#include <iostream>
#include<unordered_map>
using namespace std;

int main() {
  // creation of a map
  unordered_map<string,int> m;

  //insertion
  pair<string,int> p = make_pair("Scorpio",9);

  //now we can insert this pair into map
  m.insert(p);


  //second way of insertion
  pair<string,int> p2("alto",2);
  m.insert(p2);

  //third way of insertion
  m["fortuner"] = 20;

  // ---------------------------------------------------------------------------------
  // access
  cout<< m.at("alto")<<endl;
  cout<<m.at("Scorpio")<<endl;
  cout<<m.at("fortuner")<<endl;

  //second way of access
  cout<<m["fortuner"]<<endl;

  // ----------------------------------------------------------------------------------------
  // search
  // in map we have a count function which tells us whether the element is present or not
  cout<<m.count("Scorpio")<<endl;

  // another function for searching is
  if(m.find("fortuner") != m.end()){
    cout<<"fortuner found"<<endl;
  }
  else{
    cout<<"fortuner not found"<<endl;
  }

  // -----------------------------------------------------------------------------------
  // for size
  cout<<m.size()<<endl;

  //intersting things
  // if i try to excess let se hammer jiski entry hmare pass nhi pdi
  cout<<m["hummer"]<<endl;

  //is syntax se phele entry search krega or na milne per entry create krega and uske 
  //corressponding 0 insert kr dega
  cout<<m.size()<<endl;



  // -------------------------------------------------------------------------------------------
  // iteration on map

  cout<<"printing all entries"<<endl;
  for(auto i:m){
    cout<< i.first << " -> "<<i.second<<endl;
  }
  return 0;
}