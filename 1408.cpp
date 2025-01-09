#include <iostream>
#include <vector>
#include <string>
using namespace std;
class Solution {
 public:
  vector<string> stringMatching(vector<string>& words) {
    vector<string> ans;
    for (int i = 0; i < words.size(); i++) {
      for (int j = 0; j < words.size(); j++) {
        if (i != j) {
          if (isContained(words[i], words[j])) ans.push_back(words[i]);
        }
      }
    }
    return ans;
  }
  bool isContained(string a, string b) {
    if (a.size() > b.size()) return false;
    for (int i = 0; i < b.size(); i++) {
      if (b.substr(i, a.size()) == a) return true;
    }
  }
};

int main() {
  Solution sol;
  vector<string> words = {"leetcode", "et", "code"};
  vector<string> ans = sol.stringMatching(words);
  for (int i = 0; i < ans.size(); i++) cout << ans[i] << " ";
  return 0;
}