#include <iostream>
#include <vector>
using namespace std;

string changeString(string str) {
  for (int i = 0; i < str.length(); i++) {
    if (str[i] == '[') {
      str[i] = '{';
    }
    if (str[i] == ']') {
      str[i] = '}';
    }
  }
  return str;
}

int main() {
 ; cout << changeString(str) << endl;
  return 0;
}