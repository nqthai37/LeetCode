#include <iostream>
#include <vector>
#include <stack>
#include <string>
using namespace std;
// A parentheses string is a non - empty string consisting only of '(' and
//     ')'.It is valid if any of the following conditions is true :

//     It
//     is()
//         .It can be written as AB(A concatenated with B),
//     where A and B are valid parentheses strings.It can be written as(A),
//     where A is a valid parentheses string.You are given a
//     parentheses string s and a string locked,
//     both of length n.locked is a binary string consisting only of '0' s and
//         '1' s.For each index i of locked,

//     If locked[i] is '1', you cannot change s[i].But if locked[i] is '0',
//     you can change s[i] to either '(' or
//         ')'.Return true if you can make s a valid parentheses
//         string.Otherwise,
//     return false.

class Solution {
 public:
  bool canBeValid(string s, string locked) {
    stack<int> st;
    int n = s.size();
    // string s1 = "())()))()(()(((())(()()))))((((()())(())";
    // string s2 = "1011101100010001001011000000110010100101";
    for (int i = 0; i < n; i++) {
      if (s[i] == '(') {
        st.push(i);
      } else if (s[i] == ')') {
        if (st.empty()) {
          if (locked[i] == '1') {
            return false;
          }
          st.push(i);
        } else {
          st.pop();
        }
      }
    }

    // st= )

    if (st.size() == 0) {
      return true;
    }

    while (!st.empty()) {
      int idx = st.top();
      st.pop();
      cout << idx << s[idx] << locked[idx] << endl;
    }

    // while (!st.empty()) {
    //   int idx = st.top();
    //   st.pop();
    //   if (locked[idx] == '1') {
    //     return false;
    //   }
    // }
    return true;
  }
};

int main() {
  Solution s;
  string s1 = "())()))()(()(((())(()()))))((((()())(())";
  string s2 = "1011101100010001001011000000110010100101";
  //   cout << s.canBeValid(s1, s2) << endl;
  cout << s.canBeValid(s1, s2);
  return 0;
}