#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
 public:
  int countPrefixSuffixPairs(vector<string>& words) {
    int count = 0;
    for (int i = 0; i < words.size(); i++) {
      for (int j = 0; j < words.size(); j++) {
        if (i >= j) continue;
        if (isPreFixAndSuffix(words[i], words[j])) {
          cout << words[i] << " " << words[j] << endl;
          count++;
        }
      }
    }
    return count;
  }
  bool isPreFixAndSuffix(string& idx, string& src) {
    if (idx.size() > src.size()) return false;
    return (src.substr(0, idx.size()) == idx &&
            src.substr(src.size() - idx.size(), idx.size()) == idx);
  }
};

int main() {
  Solution sol;
  vector<string> words = {"a", "aba", "ababa", "aa"};
  cout << sol.countPrefixSuffixPairs(words) << endl;
  return 0;
}