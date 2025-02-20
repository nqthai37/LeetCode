#include <iostream>
#include <vector>
#include <string>
#include <map>
using namespace std;

class Solution {
 public:
  int minimumLength(string s) {
    if (s.size() <= 2) {
      return s.size();
    }
    map<char, int> m;
    // cout << m['a'] << endl;
    for (int i = 0; i < s.size(); i++) {
      m[s[i]]++;
    }
    for (auto it = m.begin(); it != m.end(); it++) {
      if (it->second >= 3) {
        if (it->second % 2 == 0) {
          m[it->first] = 2;
        } else {
          m[it->first] = 1;
        }
      }
    }
    int sum = 0;
    for (auto it = m.begin(); it != m.end(); it++) {
      sum += it->second;
    }
    return sum;
  }
};

int main() {
  Solution s;
  cout << s.minimumLength(
              "ucvbutgkohgbcobqeyqwppbxqoynxeuuzouyvmydfhrprdbuzwqebwuiejox"
              "sx"
              "dh"
              "bmuaiscalnteocghnlisxxawxgcjloevrdcj")
       << endl;
  return 0;
}