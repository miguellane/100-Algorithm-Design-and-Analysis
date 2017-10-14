#include <list>
#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

int main(int argc,char **argv) {

  int m;
  cin >> m;
  list<list<int> > hashTable(m);
  list<list<int> >::iterator it1;
  list<int>::iterator it2;

  string input;
  char func;
  int key = 0;

  int found = 0;

  while(func != 'e'){
//Ask Input, Split into Appropriate Parts
    cin >> input;
    func = input[0];
    input.erase(0,1);
    key = atoi(input.c_str());
//Make Iterator for List[key%mm]
    it1 = hashTable.begin();
    advance(it1, key%m);
    it2 = (*it1).begin();

    switch(func){
      case 'i':
        (*it1).push_front(key);
        break;
      case 'd':
        found = 0;
        for(int i= 0; i<(*it1).size(); i++){
          if((*it2) == key){
            (*it1).erase(it2);
            cout<<key<<":DELETED"<<";"<<endl;
            found = 1;
            break;
          }
          it2++;
        }
        if(found == 0)
          cout<<key<<":DELETE_FAILED"<<";"<<endl;
        break;
      case 's':
        found = 0;
        for(int i= 0; i<(*it1).size(); i++){
          if((*it2) == key){
            cout<<key<<":FOUND_AT"<<key%m<<","<<i<<";"<<endl;
            found = 1;
            break;
          }
          it2++;
        }
        if(found == 0)
          cout<<key<<":NOT_FOUND"<<";"<<endl;
        break;
      case 'o':
        it1 = hashTable.begin();
        for(int i = 0; i < hashTable.size(); i++){
          it2 = (*it1).begin();
          cout<<i<<":";
          for(int j = 0; j < (*it1).size(); j++){
            cout<<*it2<<"->";
            it2++;
          }
          it1++;
          cout<<";"<<endl;
        }
        break;
    }
  }
}
