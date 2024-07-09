#include <iostream>
#include<queue>
using namespace std;

int main() {
  string str = "ababc";
  queue<char>q;

  int freq[26] = {0};

  for(int i=0; i<str.length(); i++){
    char ch = str[i];
    //frequency table me store krlo
    freq[ch-'a']++;
    q.push(ch);

    //answer find kro
    while(!q.empty()){
      char frontCharacter = q.front();
      if(freq[frontCharacter-'a'] > 1){
        //mtlb ye answer nhi hai
        q.pop();
      } else{
        // ==1 wala case hai and yhi answer hai
        cout<<frontCharacter<<" ->";
        break;
      }
    }
    if(q.empty()){
      cout<<"#" << "->";
    }
  }
  return 0;
}