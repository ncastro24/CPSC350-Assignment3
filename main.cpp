#include "GenStack.h"
#include <iostream>
#include <fstream>
using namespace std;

int main(int argc, char **argv) {
  GenStack<char> userStack[20];
  string userFile;
  cout << "This is a program made to check for delimiter errors in files." << endl;
  cout << "Enter file you want to check for: " << endl;
  cin >> userFile;

  ifstream inFS;
  inFS.open(userFile);

  string str;
  int line = 0;
  char first;
  bool balance = true;

  while (getline(inFS, str)){
    line++;
    for(int i = 0; i < str.size(); ++i){
      if((str[i] == '(')||(str[i] == '{')||(str[i] == '[')){
        userStack->push(str[i]);
      }
      if (userStack->isEmpty()){
        balance = false;
      }

      switch (str[i]){
        case ')': //if we find a ')' closing...
          first = userStack->peek();
          userStack->pop();
          if(first == '{'){ //... and if the first delimiter is a '{' but it ends with ')'...
            cout << "Line " << line << ": expected } and found )" << endl;
          }
          else if(first == '['){ ///... and if the first delimiter is a '[' but it ends with ')'...
            cout << "Line " << line << ": expected ] and found )" << endl;
          }
          break;
        case '}': //if we find a '}' closing...
          first = userStack->peek();
          userStack->pop();
          if(first == '('){ //... and if the first delimiter is a '(' but it ends with '}'...
            cout << "Line " << line << ": expected ) and found }" << endl;
          }
          else if(first == '['){ //... and if the first delimiter is a '[' but it ends with '}'...
            cout << "Line " << line << ": expected ] and found }" << endl;
          }
          break;
        case ']': //if we find a ']' closing...
          first = userStack->peek();
          userStack->pop();
          if(first == '('){ //... and if the first delimiter is a '(' but it ends with ']'...
            cout << "Line " << line << ": expected ) and found ]" << endl;
          }
          else if(first == '{'){ //... and if the first delimiter is a '{' but it ends with ']'...
            cout << "Line " << line << ": expected } and found ]" << endl;
          }
          break;
        }
      }
    }

    if (balance){
      cout << "File has balanced delimiters." << endl;
    }
    else {
      cout << "Reached end of file. Missing delimiter found." << endl;
    }
}
