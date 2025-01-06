#include <bits/stdc++.h>
class Solution {
 public:
  int countPalindromicSubsequence(string s) {
    int cnt = 0;
    vector<pair<char, vector<char>>> token;
    for (int i = 0; i < s.size(); i++) {
      if (search(token, s[i])) continue;
      vector<char> temp;
      for (int j = s.size() - 1; j >= i + 2; j--) {
        if (s[i] == s[j]) {
          for (int k = i + 1; k < j; k++) {
            if (!search(temp, s[k])) {
              temp.push_back(s[k]);
              cnt++;
            }
          }
          break;
        }
      }
      token.push_back(pair(s[i], temp));
    }
    return cnt;
  }
  bool search(vector<pair<char, vector<char>>>& token, char& index) {
    for (int i = 0; i < token.size(); i++)
      if (token[i].first == index) return true;
    return false;
  }
  bool search(vector<char>& token, char& index) {
    for (int i = 0; i < token.size(); i++)
      if (token[i] == index) return true;
    return false;
  }
};

int main() {
  Solution s;
  std::cout << s.countPalindromicSubsequence("aabca") << std::endl;
  return 0;
}